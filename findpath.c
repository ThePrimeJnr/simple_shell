#include "shell.h"

char *findpath(path *head, char *command) {
    path *current = head;

    while (current != NULL) {
        char *abs_path = strcat(strcat(current->dir, "/"), command);
        struct stat st;
        if (stat(abs_path, &st) == 0) {
            return abs_path;
        }
        current = current->next;
    }

    return NULL;
}

