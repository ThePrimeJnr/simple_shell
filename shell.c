#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char *line = NULL, *command[1024];
    size_t len = 0, i = 0;
    pid_t cpid;
    struct stat st;
    int read;

    while (1)
    {
        printf("#cisfun ");
        read = getline(&line, &len, stdin);
	
	printf("read: %i\n", read);
        if (read == -1) {
            break;
        }

        command[0] = strtok(line, " \n");

        for (i = 1; command[i]; i++)
            command[i] = strtok(NULL, " \n");

        if (command[0])
        {
            if (stat(command[0], &st) == 0)
            {
                cpid = fork();
                if (cpid == -1)
                {
                    perror("Error: ");
                    return (-1);
                }
                if (cpid == 0)
                    execve(command[0], command, NULL);

            }
            else
                printf("%s: No such file or directory\n", argv[0]);
        }

        wait(&cpid);
    }

    free(line);

    return (0);
}

