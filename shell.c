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
	char *line = NULL, *command_path, *command[1024];
	int read, i = 0;
	size_t len = 0;
	path *pathv = initpath(head, env);

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		if (getline(&line, &len, stdin) == -1)
			exit(0);

		arraycpy(command, parseline(line));
		
		exec_command(command, pathv, env);

		wait(NULL);
	}
	free(line);
	return (0);
}

char **parseline(char *line)
{
    int i = 0;
    char **str = malloc(1024 * sizeof(char *));

    str[0] = strtok(line, " \n");
    for (i = 1; str[i - 1]; i++)
        str[i] = strtok(NULL, " \n");

    return str;
}


int handle_builtin(char *command[], char *env[])
{
	int i= 0;

	if(!strcmp(command[0], "exit"))
		exit(0);
	if(!strcmp(command[0], "env"))
	{
		while(env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	
	return (-1);
}

int exec_command(char *command[], path *head, char *env[])
{
	char *command_path;
	pid_t cpid;

	if (command[0])
	{
		if (handle_builtin(command, env))
		{
			command_path = findpath(head, command[0]);
			if (command_path)
			{
				cpid = fork();
				if (cpid == -1)
					return (-1);
				if (cpid == 0)
					execve(command_path, command, NULL);
			}
			else
				printf("%s: No such file or directory\n", "test");
		}
	}
}

int arraycpy(char *dest[], char *src[]) {
    int i = 0;

    while (src[i] != NULL) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = NULL;

    return i; // Returns the number of elements copied
}
