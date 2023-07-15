#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[], char *env[])
{
	char *args[] = {"/bin/sh", NULL};

	execve(args[0], args, env);
}

