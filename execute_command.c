#include "shell.h"

/**
 * execute_command -  a function to execute a command
 * @command: an array of the command to be executed
 * @shell: the name of the shell program
 * @n: the index of the command to be executed
 *
 * Return: the status of the command executed
 */
int execute_command(char *shell, int n)
{
	char *command_path;
	pid_t cpid;

	if (command[0] && handle_builtin(command))
	{
		command_path = findpath(command[0]);
		if (command_path)
		{
			cpid = fork();
			if (cpid == -1)
				return (0);
			else if (cpid == 0)
			{
				execve(command_path, command, environ);
				perror("Error");
				exit(0);
			}
			else
				wait(NULL);
		}
		else
		{
			_fprintf(2, "%s: %d: %s: not found\n", shell, n, command[0]);
			return (127);
		}
		free(command_path);
	}

	return (status);
}
