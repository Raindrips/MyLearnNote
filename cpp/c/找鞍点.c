#include <stdio.h>

int main()
{
       int a[3][4],i,j,k;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	for(i=0;i<3;i++)//i��������һ���������
	{
		int i_max = a[i][0];
		for(j=0;j<4;j++)//j������¼�����i�еĵڼ���Ԫ�رȽ�
		{
			if(a[i][j] > i_max)
			{
				i_max = a[i][j];
			}
		}

		for(j=0;j<4;j++)
		{
			if(a[i][j] == i_max)//a[i][j]�������������,���ж��Ƿ���������С
			{
				for(k=0;k<3;k++)//k������j���е���һ�е�Ԫ�ؽ��бȽ�
				{
					if(a[k][j] < i_max)//�����Ԫ�ر�i_maxС����i_max�Ͳ�����С
					{
						goto loop;
					}
				}
				printf("%d(%d,%d)\n",i_max,i,j);
				loop:;
			}
		}
	}
	
	return 0;
	
}
