#include "shell.h"

int exit_stat(char *exit_status)
{
	
	if (!exit_status)
	{
		free(line);
		free_array(command);
		exit(status);
	}

	status = _atoi(exit_status);

	if (status >= 0)
	{
		free(line);
		free_array(command);
		exit(status);
	}

	_fprintf(2, "%s: %i: exit: Illegal number: %s\n", shell, shell_index, exit_status);
	return (2);
}
