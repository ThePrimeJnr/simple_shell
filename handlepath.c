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

char **strtoarr(char *str, char delimiter)
{
	int i = 0, j = 0, k = 0;
	int str_len = strlen(str);
	char **arr = (char **)malloc(sizeof(char *) * (str_len + 1));
	char *buf = (char *)malloc(sizeof(char) * (str_len + 1));


	for (; i < str_len + 1; i++)
	{
		if (str[i] != delimiter && str[i] != '\0')
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

	return arr;
}
void free_array(char **arr) {
	if (arr == NULL)
		return;

	for (int i = 0; arr[i] != NULL; i++) {
		free(arr[i]);
	}

	free(arr);
}
char *findpath(char *command)
{
	int i = 0;
	char *path_val = _getenv("PATH");
	char **path_dir;

	if (path_val != NULL)
		path_dir = strtoarr(path_val, ':');

	if (access(command, F_OK) == 0)
		return (strdup(command));

	for (i = 0; path_dir[i]; i++)
	{
		char abs_path[1024];

		strcpy(abs_path, path_dir[i]);
		strcat(abs_path, "/");
		strcat(abs_path, command);
		if (access(abs_path, F_OK) == 0)
		{
			return (strdup(abs_path));
		}
	}

	free(path_dir);

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
