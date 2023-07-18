#include "shell.h"

path *printlist(path *head)
{
    path *current = head;
    while (current != NULL) {
        printf("%s\n", current->dir);
        current = current->next;
    }

    return head;
}
