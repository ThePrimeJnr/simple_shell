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
	shell = argv[0];
	shell_index = 0;
	status = 0;

	(void)argc;
	while (++shell_index)
	{
		print_prompt("#cisfun$ ");

		_getline(&line);

		command = strtoarr(line, ' ');

		status = execute_command();

		free(line);
		free_array(command);
	}

	return (status);
}
