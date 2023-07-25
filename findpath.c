#include "shell.h"

/**
 * findpath - searches through the directories to find a command
 * @command: The command to search for (
 *
 * Return: absolute path to the command if found, else NULL
 */
char *findpath(char *command)
{
	int i = 0;
	char *path_val = _getenv("PATH");
	char **path_dir, *abs_path;

	if (access(command, F_OK) == 0)
		return (strdup(command));

	if (!path_val)
		return (NULL);

	path_dir = strtoarr(path_val, ':');

	for (i = 0; path_dir[i]; i++)
	{
		abs_path = malloc(1024);
		strcpy(abs_path, path_dir[i]);
		strcat(abs_path, "/");
		strcat(abs_path, command);
		
		if (access(abs_path, F_OK) == 0)
		{
			free_array(path_dir);
			return (abs_path);
		}
		free(abs_path);
	}
	free_array(path_dir);

	return (NULL);
}
