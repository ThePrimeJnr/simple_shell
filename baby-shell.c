#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *line = NULL, *array[1024];
	size_t len = 0, i = 0;
	pid_t cpid;

	while(1)
	{
		printf("$ ");
		getline(&line, &len, stdin);

		array[0] = strtok(line, " \n");

		while (array[i])
		{
			i++;
			array[i] = strtok(0, " \n");
		}

		cpid = fork();
		if (cpid == 0)
			execve(array[0], array, NULL);

		wait(&cpid);
	}

	return (0);
}
