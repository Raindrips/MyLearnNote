#include <stdio.h>



int main()
{
	int a[10],i,j,t;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<10;i++)//i����ð�ݵ�����
	{
		for(j=0;j<9-i;j++)//j����ð�ݵ��ڼ�����
		{
			if(a[j] > a[j+1])//��������Ԫ�رȽ�
			{
				t = a[j];//t������ǽ�Ҫ�����ǵ�ֵ
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
