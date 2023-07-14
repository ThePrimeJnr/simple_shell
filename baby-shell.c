#include <stdio.h>

int main(void)
{
	char string;

	for(int i=1;i;i++)
	{
		printf("$ ");
		scanf("%s", &string);

		printf("%c\n\n", string);
	}
	return (0);
}
