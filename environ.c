#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	for (int i = 0; environ[i]; i++) {
		printf("%s\n", environ[i]);
	}
	return (0);
}
