#include "shell.h"

/**
 * _atoi -  a function that converts a string to integers
 * @str: the string to be converted
 *
 * Return: the resulting integer
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		return (-2);

		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (sign * result);
}
