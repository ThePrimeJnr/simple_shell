#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <sys/wait.h>

#define _INT_MIN (1 << (sizeof(int) * 8 - 1))
typedef struct path
{
	char *dir;
	struct path *next;
} path;

path *initpath(void);
path *printpath(path *head);
char *findpath(path *head, char *command);
int handle_builtin(char *command[], int n);
int arraycpy(char *dest[], char *src[]);
char **parseline(char *line);
int execute_command(char *command[], int n, char *shell);
int printarray(char *array[]);
char *_getenv(char *);
path *printlist(path *head);
int _fputchar(int fd, char c);
int _fputint(int fd, int num);
int _fputstr(int fd, char *str);
int _fprintf(int fd, const char *format, ...);
int print_prompt(char *prompt);
ssize_t _getline(char **line);
ssize_t _getchar(char c);
extern char **environ;
path *envpath;
int status;

#endif /* SHELL_H */
