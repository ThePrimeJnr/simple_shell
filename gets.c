#include "shell.h"

ssize_t _getline(char **line)
{
	char buf[1024];
	ssize_t n = 0, status = 1;

	while ((status = read(0, &buf[n], 1)) && (buf[n] != '\n'))
	{
		n++;
	}

	*line = malloc(sizeof(char) * (n + 1));	
	
	if (buf[n] == '\n')
	{
		buf[n] = '\0';
		strcpy(*line, buf);
		return (n);
	}
	else
	{
		buf[n] = '\0';
		if (n == 0)
		{
			if (isatty(0))
				_fprintf(1, "\n");
			exit (0);
		}
		else
		{
			strcpy(*line, buf);
			return (-1);
		}
	}
}
