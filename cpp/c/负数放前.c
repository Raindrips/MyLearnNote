#include <stdio.h>

int main()
{
	int a[10]={0},i=0,j=0,tmp;

	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		if(a[i] < 0)
		{
			tmp = a[i];//tmp������ǽ�Ҫ��ʧ��ֵ
			a[i] = a[j];
			a[j] = tmp;
			j++;
		}
	}

	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	putchar('\n');
	
	return 0;
}
