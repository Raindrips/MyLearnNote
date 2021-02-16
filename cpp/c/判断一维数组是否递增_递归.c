#include <stdio.h>

/*
	int is_Inc(int a[],int n)
	功能:判断数组a的前n项元素是否递增，是返回1，不是返回0
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
