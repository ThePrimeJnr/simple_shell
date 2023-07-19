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

char *findpath(path *head, char *command) {
    if (access(command, X_OK) == 0) {
        return strdup(command);
    }

    path *current = head;

    while (current != NULL) {
        char abs_path[1024];
        snprintf(abs_path, sizeof(abs_path), "%s/%s", current->dir, command);
        if (access(abs_path, X_OK) == 0) {
            return strdup(abs_path);
        }
        current = current->next;
    }

    return NULL;
}

path *printlist(path *head)
{
    path *current = head;
    while (current != NULL) {
        printf("%s\n", current->dir);
        current = current->next;
    }

    return head;
}
