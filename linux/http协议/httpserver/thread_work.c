#include"thread_work.h"
#include"pub.h"
#include <sys/types.h>
#include <sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define HEAD "HTTP/1.0 200 OK\n\
Content-Type: %s\n\
Transfer-Encoding: chunked\n\
Connection: Keep-Alive\n\
Accept-Ranges:bytes\n\
Content-Length:%d\n\n"
#define TAIL "\n\n"
extern char LOGBUF[1024];




/*****************************************************************************
 �� �� ��  : get_http_command
 ��������  : ����HTTP����
 �������  : char *http_msg  
             char *command   
 �������  : ��
 �� �� ֵ  : void
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2017��11��25��
    ��    ��   : chandler
    �޸�����   : �����ɺ���

*****************************************************************************/
void get_http_command(char *http_msg, char *command)
{
	char *p_end = http_msg;
	char *p_start = http_msg;
	while (*p_start) //GET /
	{
		if (*p_start == '/')
		{
			break;
		}
		p_start++;
	}
	p_start++;
	p_end = strchr(http_msg, '\n');
	while (p_end != p_start)
	{
		if (*p_end == ' ')
		{
			break;
		}
		p_end--;
	}
	strncpy(command, p_start, p_end - p_start);  //URL

}

//根据用户在GET中的请求，生成相应的回复内容
int make_http_content(const char *command, char **content)
{
	char *file_buf;
	int file_length;
	char headbuf[1024];

	if (command[0] == 0)
	{
		file_length = get_file_content("index.html", &file_buf);
	} else
	{
		file_length = get_file_content(command, &file_buf);
	}
    
	if (file_length == 0)
	{
		return 0;
	}

	memset(headbuf, 0, sizeof(headbuf));
	sprintf(headbuf, HEAD, get_filetype(command), file_length); 

	int iheadlen = strlen(headbuf); 
	int itaillen = strlen(TAIL); 
	int isumlen = iheadlen + file_length + itaillen; 
	*content = (char *) malloc(isumlen); 
	if(*content==NULL)
	{
		memset(LOGBUF,0,sizeof(LOGBUF));
		sprintf(LOGBUF,"malloc failed %s\n", strerror(errno));
		save_log(LOGBUF);
	}
	char *tmp = *content;
	memcpy(tmp, headbuf, iheadlen); //安装消息�?
	memcpy(&tmp[iheadlen], file_buf, file_length); //安装消息�?
	memcpy(&tmp[iheadlen] + file_length, TAIL, itaillen); //安装消息�?
	//printf("headbuf:\n%s", headbuf);
	if (file_buf)
	{
		free(file_buf);
	}
	return isumlen; //返回消息总长�?
}
void *http_thread(void *argc)
{
	//printf("thread begin \n");
	if(argc==NULL)
	{
		return NULL;
	}
	int st = *(int *) argc;
	free((int *)argc);
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	int rc = recv(st, buf, sizeof(buf), 0);
	if (rc <= 0)
	{
		memset(LOGBUF,0,sizeof(LOGBUF));
		sprintf(LOGBUF,"recv failed %s\n", strerror(errno));
		save_log(LOGBUF);
	} else
	{
		//printf("recv:\n%s", buf);
		char command[1024];
		memset(command, 0, sizeof(command));
		get_http_command(buf, command); 
		printf("get:%s \n", command);
		char *content = NULL;
		int ilen = make_http_content(command, &content); 
		{
			send(st, content, ilen, 0); 
			free(content);
		}
	}
	close(st); 
	//printf("thread_is end\n");
	return NULL;

}
