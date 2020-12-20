#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define OPEN_FILE "./log"

int main()
{

	int fd = open(OPEN_FILE, O_RDWR | O_CREAT, 0666);
	if( fd < 0 ){
		perror("open");
		return 1;
	}
	printf("dup begin : %d\n",fd);
	//------dup()-----
	//close(1);              //需要手动关闭为呢见描述符
	//dup(); uses  the lowest-numbered unused descriptor for the new descriptor.
	//int new_fd = dup(fd);
	
	//-----dup2()------
	int new_fd = dup2(fd, 1);//不许要手动关闭文件描述符号,两个参数分别为旧、新，把旧的描述符关闭，再把新的描述符复制到旧的上面。
	printf("dup end : new : %d, old : %d\n",new_fd,fd);
	int count = 10;
	while(count){
		printf("hello world ; %d\n",count);
		count--;
	}
	fflush(stdout);//重定向到文件就由行缓冲变成满缓冲，所以得刷新
	close(fd);
	return 0;
}
