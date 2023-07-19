#include "shell.h" 

/**
* main - Entry point
* @argc: argument count
* @argv: argumen vector
* @env: environment variable
*
* Return: 0 for success, others for failure
*/

int main(int argc, char *argv[], char *env[])
{
	char *line = NULL, *command[1024];
	int read, i = 0;
	size_t len = 0;
	pid_t cpid;
	path *head = initpath(head, env);

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
			exit(0);

		command[0] = strtok(line, " \n");
		for (i = 1; command[i - 1]; i++)
			command[i] = strtok(NULL, " \n");

		if (command[0])
		{
			if (!strcmp(command[0], "exit"))
				return (0);
			command[0] = findpath(head, command[0]);
			if (command[0])
			{
				cpid = fork();
				if (cpid == -1)
					return (-1);
				if (cpid == 0)
					execve(command[0], command, NULL);
			}
			else
				printf("%s: No such file or directory\n", argv[0]);
		}

		wait(&cpid);
	}

	free(line);

	return (0);
}
