#include <stdio.h>
/*
	a1=10,  an =an-1 + 2;
	(1)���n���ֵ
	(2)��ǰn��ĺ�
	
*/

/*
	int An(int n)
	����:���ص�n���ֵ
*/
int An(int n)
{
	if(n == 1)
	{
		return 10;
	}
	return An(n-1)+2;
}

/*
	int Sn(int n)
	����:����ǰn��ĺ�
*/
int Sn(int n)
{
	if(n==1)
	{
		return An(1);
	}
	return Sn(n-1) + An(n);
}

int main()
{
	int n;
	scanf("%d",&n);
	
	printf("An is %d,Sn is %d\n",An(n),Sn(n));
	return 0;
}
