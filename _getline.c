#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t nbyte;

	nbyte = fread(lineptr, 1, *n, stream);

	return (nbyte);
}
