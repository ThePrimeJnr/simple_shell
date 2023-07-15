#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 1;
	struct stat st;

	if (argc < 2)
		return (-1);

	while (argv[i])
	{
		if (stat(argv[i], &st) == 0)
			printf("%s\n", argv[i]);
		else
		{
			printf("%s not found\n", argv[i]);
		}
		i++;
	}
}
