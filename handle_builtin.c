#include "shell.h"

/**
 * handle_builtin - Handles builtin commands like exit, env, e.t.c
 * @command: The command to be executed
 *
 * Return: 0 for success, else status
 */
int handle_builtin(char *command[])
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
