#include <stdio.h>
/*
	int jie(int n)
	����:����n�Ľ׳�		
*/

int jie(int n)
{
	if(n == 1)
	{
		return 1;
	}
	return n*jie(n-1);
}

int main()
{
	int n;
	scanf("%d",&n);
	
	printf("value is %d\n",jie(n));

	return 0;
}
