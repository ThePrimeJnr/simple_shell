#include "shell.h"

/**
 * _fputchar - writes the character c to stdout
 * @fd: file descriptor
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _fputchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

/**
 * _fputstr - Prints a string to standard output
 * @fd: file descriptor
 * @str: The string to be printed
 *
 * Return: Length of string printed - 1
 */
int _fputstr(int fd, char *str)
{
	int i;

	if (!str)
		return (_fputstr(fd, "(null)"));
	for (i = 0; str[i]; i++)
		_fputchar(fd, str[i]);

	return (i);
}

/**
 * _fputint - Prints an integer to standard output
 * @fd: file desriptor
 * @num: The number to be printed
 *
 * Return: Length of string printed - 1
 */
int _fputint(int fd, int num)
{
	int val, len = 0;

	if (!num)
	{
		len += _fputchar(fd, '0');
		return (len);
	}
	if (num == _INT_MIN)
	{
		len += _fputstr(fd, "-2147483648");
		return (len);
	}
	if (num < 0)
	{
		len += _fputchar(fd, '-');
		num = -num;
	}

	val = num % 10;
	num = num / 10;
if (num)
		len += _fputint(fd, num);
	len += _fputchar(fd, val + '0');

	return (len);
}

/**
 * _fprintf - Prints to the standar output like regular printf
 * @fd: file descriptor
 * @format: The string to be printed adn its format specifiers
 *
 * Return: Length of printed string
 */
int _fprintf(int fd, const char *format, ...)
{
	va_list ls_args;
	int i = 0, len = 0;

	va_start(ls_args, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += _fputchar(fd, format[i]);
			else
			{
			i++;
			if (format[i] == 's')
				len += _fputstr(fd, va_arg(ls_args, char *));
				else if (format[i] == 'd' || format[i] == 'i')
				len += _fputint(fd, va_arg(ls_args, int));
		}
		i++;
	}
	va_end(ls_args);

	return (len);
}

/**
 * _printarray - prints an array to standard output
 * @array: The array to be printed
 *
 * Return: Numbers of elements printed
 */
int printarray(char *array[])
{
	int i = 0;

	while (array[i])
	{
		_fprintf(1, "%s\n", array[i]);
		i++;
	}
	return (0);
}
