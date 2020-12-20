#include <stdio.h>


int main()
{
	int a[10],i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<9;i++)
	{
		if(a[i+1]<a[i])
		{
			printf("no\n");
			goto loop;
		}
	}


	printf("yes\n");
loop:;
	
	return 0;
}
