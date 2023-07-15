#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *array[] = {"/usr/bin/ls", "-l", "-a", NULL};
	int cpid;

	cpid = fork();

	if (cpid == 0)
		execve(array[0], array, NULL);

	//wait(&cpid);
	printf("End\n");
	return (0);
}
