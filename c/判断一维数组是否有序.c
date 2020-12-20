#include <stdio.h>

int flag_inc = 0;//递增标志位，如果出现了递增的现象则置1
int flag_dec = 0;//递减标志位，如果出现了递减的现象则置1


int main()
{
	int a[10],i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<9;i++)
	{
		if(a[i+1] > a[i])//递增现象出现了
		{
			flag_inc = 1;
		}
		if(a[i+1] < a[i])//递减现象出现了
		{
			flag_dec = 1;
		}

		if(flag_inc && flag_dec)//递增和递减的现象都出现了，则无序
		{
			printf("no\n");
			goto loop;
		}
	}

	printf("yes\n");
	loop:;
	return 0;
}
