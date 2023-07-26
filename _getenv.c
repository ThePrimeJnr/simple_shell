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
