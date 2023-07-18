#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct path
{
    char *dir;
    struct path *next;
} path;

int main(int argc, char *argv[], char *env[])
{
    char *var, *value;
    path *head, *temp;

    head = NULL; // Initialize head to NULL

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

    // Traverse and print each element in the linked list
    path *current = head;
    while (current != NULL) {
        printf("%s\n", current->dir);
        current = current->next;
    }

    // Free memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

