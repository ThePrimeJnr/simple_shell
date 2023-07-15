#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	extern char** environ;
	int i;
	char *name = "ZSH";

	for (i = 0; environ[i] != NULL; ++i)
	{
		if (strcmp(strtok(environ[i], "="), name) == 0)
		{
			printf("%s\n", strtok(0, "="));
			return (0);
		}
	}

	printf("%s\n", "Not Found");
	return (1);
}

