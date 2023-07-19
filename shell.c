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
	char *line = NULL;
	size_t len = 0;
	pathv = initpath();

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		if (getline(&line, &len, stdin) == -1)
			exit(0);

		if (exec_command(parseline(line)))
			printf("%s: No such file or directory\n", argv[0]);

		wait(NULL);
	}
	free(line);
	return (0);
}


char **parseline(char *line)
{
    int i = 0;
    char **command = malloc(1024 * sizeof(char *));

    command[0] = strtok(line, " \n");
    for (i = 1; command[i - 1]; i++)
        command[i] = strtok(NULL, " \n");

    return command;
}


int exec_command(char *command[])
{
	char *command_path;
	pid_t cpid;

	if (command[0])
	{
		if (handle_builtin(command))
		{
			command_path = findpath(pathv, command[0]);
			if (command_path)
			{
				cpid = fork();
				if (cpid == -1)
					return (0);
				if (cpid == 0)
				{
					execve(command_path, command, environ);
					exit(0);
				}
			}
			else
				return (-1);
		}
	}

	return (0);
}


int handle_builtin(char *command[])
{
	if(!strcmp(command[0], "exit"))
		exit(0);
	else if(!strcmp(command[0], "env"))
		printarray(command);
	
	return (-1);
}

int printarray(char *array[])
{
	int i = 0;

	while(array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}
