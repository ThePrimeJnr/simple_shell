#include "shell.h"

path *initpath()
{
	int i;
	char *path_env = NULL;
	char *path_copy = NULL;
	char *dir = NULL;
	path *head = NULL;
	path *temp = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (!strncmp(environ[i], "PATH=", 5))
		{
			path_env = environ[i] + 5;
			break;
		}
	}

	if (path_env)
	{
		path_copy = strdup(path_env);
		if (!path_copy)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		dir = strtok(path_copy, ":");
		while (dir)
		{
			temp = malloc(sizeof(path));
			if (!temp)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
			temp->dir = strdup(dir);
			temp->next = head;
			head = temp;

			dir = strtok(NULL, ":");
		}

		free(path_copy);
	}

	return (head);
}

char *findpath(path *head, char *command)
{
	path *current = head;

	if (access(command, X_OK) == 0)
		return (strdup(command));

	while (current != NULL)
	{
		char abs_path[1024];

		strcpy(abs_path, current->dir);
		strcat(abs_path, "/");
		strcat(abs_path, command);
		if (access(abs_path, X_OK) == 0)
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
