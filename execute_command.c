#include "shell.h"

/**
 * execute_command -  a function to execute a command
 *
 * Return: the status of the command executed
 */
int execute_command(void)
{
	char *command_path;
	pid_t cpid;
	int exit_status;

	if (command[0] && handle_builtin())
	{
		command_path = findpath();
		if (command_path)
		{
			cpid = fork();
			if (cpid == -1)
				return (0);
			else if (cpid == 0)
			{
				execve(command_path, command, environ);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(cpid, &exit_status, 0);
				if (WIFEXITED(exit_status))
					status = WEXITSTATUS(exit_status);
			}
		}
		else
		{
			_fprintf(2, "%a: %b: %c: not found\n", shell, shell_index, command[0]);
			return (127);
		}
		free(command_path);
	}

	return (status);
}
