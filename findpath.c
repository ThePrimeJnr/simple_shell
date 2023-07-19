#include "shell.h"

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

