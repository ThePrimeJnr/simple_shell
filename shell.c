#include "shell.h" 

/**
* main - Entry point
* @argc: argument count
* @argv: argumen vector
*
* Return: 0 for success, others for failure
*/

int main(int argc, char *argv[], char *env[])
{
	char *line = NULL, *command[1024];
	int read;
	size_t len = 0, i = 0;
	pid_t cpid;
	path *head;
	struct stat st;

	head = initpath(head, env);

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		read = getline(&line, &len, stdin);

		if (read == -1)
			break;

		command[0] = strtok(line, " \n");

		for (i = 1; command[i - 1]; i++)
			command[i] = strtok(NULL, " \n");

		if (command[0])
		{
			if (strcmp(command[0], "exit") == 0)
				return (1);
			command[0] = findpath(head, command[0]);
			if (command[0] != NULL)
			{
				cpid = fork();
				if (cpid == -1)
				{
					perror("Error: ");
					return (-1);
				}
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
