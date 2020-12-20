#include <stdio.h>



int main()
{
	int a[10],i,j,t;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<10;i++)//i决定冒泡的轮数
	{
		for(j=0;j<9-i;j++)//j决定冒泡到第几个数
		{
			if(a[j] > a[j+1])//相邻两个元素比较
			{
				t = a[j];//t保存的是将要被覆盖的值
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	putchar('\n');
	return 0;
}
