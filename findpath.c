#include "shell.h"

char *findpath(path *head, char *command) {
    path *current = head;

    while (current != NULL) {
        char abs_path[1024];
        snprintf(abs_path, sizeof(abs_path), "%s/%s", current->dir, command);
        struct stat st;
        if (stat(abs_path, &st) == 0) {
            return strdup(abs_path);
        }
        current = current->next;
    }

    return NULL;
}

