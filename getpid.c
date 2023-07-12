#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("pid: %d\n", getppid());

	return (0);
}
