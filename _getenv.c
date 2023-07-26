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
		if (!_strncmp(environ[i], var, _strlen(var)) && environ[i][_strlen(var)] == '=')
		{
			value = environ[i] + _strlen(var) + 1;
			return (value);
		}
	}
	return (value);
}
