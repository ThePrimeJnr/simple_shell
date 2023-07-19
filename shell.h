#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct path
{
	char *dir;
	struct path *next;
} path;

path *initpath(path *head, char *env[]);
path *printpath(path *head);
char *findpath(path *head, char *command);
int handle_builtin(char *command[], char *env[]);
int arraycpy(char *dest[], char *src[]);
char **parseline(char *line);
int exec_command(char *command[], path *head, char *env[]);

#endif /* SHELL_H */
