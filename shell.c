#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argumen vector
 *
 * Return: 0 for success, others for failure
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	int n = 1, status = 0;

	pathv = initpath();

	while (n)
	{
		if (isatty(0))
			printf("$ ");

		if (getline(&line, &len, stdin) == -1)
			exit(status);

		if (exec_command(parseline(line)))
		{
			fprintf(stderr, "%s: %d: %s: not found\n", argv[0], n, parseline(line)[0]);
			status = 127;
		}
		n++;
	}
	free(line);
	return (status);
}


char **parseline(char *line)
{
	int i = 0;
	char **command = malloc(1024 * sizeof(char *));

	command[0] = strtok(line, " \n");
	for (i = 1; command[i - 1]; i++)
		command[i] = strtok(NULL, " \n");

	return (command);
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
                    perror("Error");
                    exit(0);
		}
                else
                    wait(NULL);
                free(command_path);
            }
            else
                return (127);
        }
    }

    return (0);
}

int handle_builtin(char *command[])
{
	if (!strcmp(command[0], "exit"))
		exit(0);
	else if (!strcmp(command[0], "env"))
	{
		printarray(environ);
		return (0);
	}

	return (-1);
}

int printarray(char *array[])
{
	int i = 0;

	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}
