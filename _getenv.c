#include "shell.h"

/**
 * _getenv - Finds a environment variable name and returns it's value
 * @var: The variable name to be found
 *
 * Return: a pointer to the varible's value
 */
char *_getenv(char *var)
{
	int i, str_len = _strlen(var);
	char *value = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(environ[i], var, str_len) && environ[i][str_len] == '=')
		{
			value = environ[i] + _strlen(var) + 1;
			return (value);
		}
	}
	return (value);
}
