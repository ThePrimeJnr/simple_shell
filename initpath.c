#include "shell.h"

path *initpath(path *head, char *env[])
{
    char *var, *value;
    path *temp;

    head = NULL;

    var = strtok(env[0], "=");

    for (int i = 1; env[i]; i++)
    {
        var = strtok(env[i], "=");

        if (!strcmp(var, "PATH"))
        {
            value = strtok(NULL, "=");

	    temp = malloc(sizeof(path));
            temp->dir = strtok(value, ":");
            while(temp->dir)
            {
                temp->next = head;
                head = temp;

		temp = malloc(sizeof(path));
                temp->dir = strtok(NULL, ":");
            }
            break;
        }
    }

    return head;
}

