#include <stdio.h>

int main()
{
	char c;
	c = getchar();

	if(c>='A' && c<='Z')
	{
		putchar(c+32);
	}
	else if(c>='a' && c<='z')
	{
		putchar(c-32);
	}
	else
	{
		printf("this is not letter");
	}
	putchar('\n');
	
}
