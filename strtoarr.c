#include "shell.h"

/**
 * strtoarr - converts a string to an array based on a delimiter
 * @str: the string to be converted to an array
 * @delim: the delimiter used to break string
 *
 * Return: array of the tokenized string, else NULl if not converted
 */
char **strtoarr(char *str, char delim)
{
	int i = 0, j = 0, k = 0;
	int str_len = strlen(str);
	char **arr = (char **)malloc(sizeof(char *) * (str_len + 1));
	char *buf = (char *)malloc(sizeof(char) * (str_len + 1));


	for (; i < str_len + 1; i++)
	{
		if (str[i] != delim && str[i] != '\0')
		{
			buf[k] = str[i];
			k++;
		}
		else
		{
			if (k > 0)
			{
				buf[k] = '\0';
				arr[j] = malloc(sizeof(char) * (k + 1));
				strcpy(arr[j], buf);
				j++;
				k = 0;
			}
		}
	}

	arr[j] = NULL;
	free(buf);

	return (arr);
}
