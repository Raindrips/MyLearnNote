#include <stdio.h>



int main()
{
	int a[10],i,j,t;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<10;i++)//i������һ��Ԫ����Ϊ��¼��
	{
		for(j=i+1;j<10;j++)//j������¼������һ��Ԫ�رȽ�
		{
			if(a[j] < a[i])
			{
				t = a[i];//t������ǽ�Ҫ�����ǵ�ֵ
				a[i] = a[j];
				a[j] = t;
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
