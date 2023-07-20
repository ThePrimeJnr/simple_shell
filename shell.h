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

path *initpath();
path *printpath(path *head);
char *findpath(path *head, char *command);
int handle_builtin(char *command[]);
int arraycpy(char *dest[], char *src[]);
char **parseline(char *line);
int exec_command(char *command[]);
int printarray(char *array[]);
char *_getenv(char *);

extern char **environ;
path *pathv;

#endif /* SHELL_H */
