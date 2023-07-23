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

	envpath = initpath();

	for (n = 1; argc; n++)
	{
		print_prompt("$ ");

		if (getline(&line, &len, stdin) == -1)
		{
			if (isatty(0))
			{
				if (n == 1)
				{
					_fprintf(1, "\n");
					break;
				}
				else
				{
					main(argc, argv);
				}
			}
			else
				exit(status);
		}
		status = execute_command(parseline(line), n, argv[0]);
	}

	free(line);
	return (status);
}

/**
 * print_prompt - prints the prompt to standard output
 * @prompt: prompt to be printed
 *
 * Return: 0 in interactive mode and 1 in non interactive mode
 */
int print_prompt(char *prompt)
{
	if (isatty(0))
	{
		_fputstr(1, prompt);
		return (0);
	}
	return (1);
}

/**
 * parseline - Tokenizes the line to get command and it's arguments
 * @line: line to be tokenized
 *
 * Return: Pointer to the command and its arguments
 */
char **parseline(char *line)
{
	int i = 0;
	char **command = (char **)malloc(1024);

	command[i] = strtok(line, " \n");
	for (i = 1; command[i - 1]; i++)
		command[i] = strtok(NULL, " \n");

	return (command);
}


int execute_command(char *command[], int n, char *shell)
{
	char *command_path;
	pid_t cpid;

	if (command[0] && handle_builtin(command, n))
	{
		command_path = findpath(envpath, command[0]);
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
	}

	return (0);
}

/**
 * handle_builtin - Handles builtin commands like exit, env, e.t.c
 * @command: The command to beexecuted*/
int handle_builtin(char *command[], int n)
{
	if (!strcmp(command[0], "exit"))
	{
		if (n == 1 || isatty(0))
			exit(0);
		exit(2);
	}
	else if (!strcmp(command[0], "env"))
	{
		printarray(environ);
		return (0);
	}

	return (-1);
}
