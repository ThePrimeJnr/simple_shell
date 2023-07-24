#include "shell.h"

/**
 * _getenv - Finds a environment variable name and returns it's value
 * @var: The variable name to be found
 *
 * Return: a pointer to the varible's value
 */
char *_getenv(char *var)
{
	int i;
	char *value = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (!strncmp(environ[i], var, strlen(var)) && environ[i][strlen(var)] == '=')
		{
			value = environ[i] + strlen(var) + 1;
			return (value);
		}
	}
	return (value);
}

char *findpath(path *head, char *command)
{
	int i = 0;
	path_val = _getenv("PATH");

	if (access(command, F_OK) == 0)
		return (strdup(command));

	while (current != NULL)
	{
		char abs_path[1024];

		strcpy(abs_path, current->dir);
		strcat(abs_path, "/");
		strcat(abs_path, command);
		if (access(abs_path, F_OK) == 0)
		{
			return (strdup(abs_path));
		}
		current = current->next;
	}

	return (NULL);
}

path *printlist(path *head)
{
	path *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->dir);
		current = current->next;
	}

	return (head);
}
