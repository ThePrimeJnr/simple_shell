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
	int index = 0;

	status = 0;
	while (1)
	{
		print_prompt("$ ");

		_getline(&line);

		command = strtoarr(line, ' ');

		status = execute_command(command, argv[0], index++);

		free(line);
		free_array(command);
	}

	return (status);
}
