#include <stdio.h>

void fun(void)
{
	char c = getchar();
	if(c == '#')
	{
		return ;
	}
	fun();
	putchar(c);	
}

int main()
{
	fun();
	putchar('\n');
	return 0;
}
