#include <stdio.h>

/*
	int is_Inc(int a[],int n)
	����:�ж�����a��ǰn��Ԫ���Ƿ�������Ƿ���1�����Ƿ���0
*/

int is_Inc(int a[],int n)
{
	if(n == 1)
	{
		return 1;
	}
	return is_Inc(a,n-1) && (a[n-1] >= a[n-2]);
}
int main()
{
	int a[10],i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}

	if(is_Inc(a ,10))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}
