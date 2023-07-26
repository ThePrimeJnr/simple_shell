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
#include <limits.h>
#define _INT_MIN (1 << (sizeof(int) * 8 - 1))

char *findpath(void);
int handle_builtin(void);
int arraycpy(char *dest[], char *src[]);
int execute_command(void);
int printarray(char *array[]);
char *_getenv(char *);
void free_array(char **arr);
int _fputchar(int fd, char c);
int _fputint(int fd, int num);
int _fputstr(int fd, char *str);
int _fprintf(int fd, const char *format, char *s1, int n1, char *s2);
char **strtoarr(char *str, char delim);
int print_prompt(char *prompt);
ssize_t _getline(char **line);
ssize_t _getchar(char c);
int exit_stat(char *exit_status);
int _atoi(const char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(const char *str1, const char *str2, size_t n);

extern char **environ;
int status;
char *line;
char **command;
int shell_index;
char *shell;

#endif /* SHELL_H */

