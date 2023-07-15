#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *env[])
{
	int i =0;
	while(strcmp(strtok(env[i], "="), argv[1]))
		i++;

	printf("%s", strtok(0, "="));
	return (0);
}
