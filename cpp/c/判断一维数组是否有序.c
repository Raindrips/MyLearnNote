#include <stdio.h>

int flag_inc = 0;//������־λ����������˵�������������1
int flag_dec = 0;//�ݼ���־λ����������˵ݼ�����������1


int main()
{
	int a[10],i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<9;i++)
	{
		if(a[i+1] > a[i])//�������������
		{
			flag_inc = 1;
		}
		if(a[i+1] < a[i])//�ݼ����������
		{
			flag_dec = 1;
		}

		if(flag_inc && flag_dec)//�����͵ݼ������󶼳����ˣ�������
		{
			printf("no\n");
			goto loop;
		}
	}

	printf("yes\n");
	loop:;
	return 0;
}
