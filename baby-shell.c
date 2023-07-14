#include <stdio.h>
#include <string.h>
#include "main.h"

int main(void)
{
	char *line = NULL, *tokenized, *token = " ";
	size_t len = 0;

	while(1)
	{
		printf("$ ");
		getline(&line, &len, stdin);

		tokenized = strtok(line, token);
		while (tokenized)
		{
			printf("%s\n", tokenized);
			tokenized = strtok(0, token);
		}
	}

	return (0);
}
