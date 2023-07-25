#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 for success, others for failure
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	char **command;
	int i;

	status = 0;
	for (argc = 1; argc; argc++)
	{
		print_prompt("$ ");

		_getline(&line);

		command = strtoarr(line, ' ');	


		status = execute_command(command, argv[0], argc);
		free(line);

		free_array(command);

		command = NULL;
	}

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
		_fputstr(1, prompt);

	return (0);
}

/**
 * _getline - gets string from statndard input and stores in a buffer
 * @line: buffer for the string to be stored
 *
 * Return: number of characters read, if errror returns -1;
 */
ssize_t _getline(char **line)
{
	char buf[8024];
	ssize_t n = 0;

	while ((read(0, &buf[n], 1)) > 0 && (buf[n] != '\n'))
		n++;
	
	if (buf[n] == '\n')
	{
		*line = malloc(sizeof(char) * (n + 1));
		buf[n] = '\0';
		strcpy(*line, buf);
		return (n);
	}
	else if (n != 0)
	{
		buf[n] = '\0';
		*line = malloc(sizeof(char) * (n + 1));
		strcpy(*line, buf);
		return (-1);
	}
	else
	{
		if (isatty(0))
			_fprintf(1, "\n");
		exit (status);
	}
}

int execute_command(char *command[], char *shell, int n)
{
	char *command_path;
	pid_t cpid;

	if (command[0] && handle_builtin(command, n))
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
				waitpid(cpid, &status, 0);
		}
		else
		{
			_fprintf(2, "%s: %d: %s: not found\n", shell, n, command[0]);
			status = 127;
			return (status);
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
		exit(status);
	}
	else if (!strcmp(command[0], "env"))
	{
		printarray(environ);
		return (0);
	}

	return (-1);
}
