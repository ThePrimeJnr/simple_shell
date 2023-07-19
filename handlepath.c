#include "shell.h"
/**
 *
 *
 */
path *initpath()
{
	int i;
	char *var, *value;
	path *head, *temp;

	head = NULL;

	var = strtok(environ[0], "=");

	for (i = 1; environ[i]; i++)
	{
		var = strtok(environ[i], "=");

		if (!strcmp(var, "PATH"))
		{
			value = strtok(NULL, "=");

			temp = malloc(sizeof(path));
			temp->dir = strtok(value, ":");
			while (temp->dir)
			{
				temp->next = head;
				head = temp;

				temp = malloc(sizeof(path));
				temp->dir = strtok(NULL, ":");
			}
			break;
		}
	}

	return (head);
}

char *findpath(path *head, char *command)
{
	if (access(command, X_OK) == 0)
		return (strdup(command));


	path *current = head;

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
