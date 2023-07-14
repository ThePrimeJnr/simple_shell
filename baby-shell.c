#include <stdio.h>
#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;

	while(1)
	{
		printf("$ ");
		getline(&line, &len, stdin);

		printf("%s\n", line);
	}
	return (0);
}
