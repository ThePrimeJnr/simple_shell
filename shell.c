#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char *shell = "/bin/sh";
	char *args[] = {"/bin/sh", NULL};
	char *env[] = {NULL};

	execve(shell, args, env);
	exit(EXIT_FAILURE);
}
