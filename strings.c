#include "shell.h"

/**
 * _strcat - concatinates two strings
 * @dest: Destination of the string to be appended
 * @src: String appended to dest
 * Return: pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int destIndx = 0, srcIndx = 0;

	for (; dest[destIndx] != '\0'; destIndx++)
		;
	for (; src[srcIndx] != '\0'; srcIndx++)
	{
		dest[destIndx] = src[srcIndx];
		destIndx++;
	}
	dest[destIndx] = '\0';
	return (dest);
}


/**
 * _strcpy - copies the string pointed to by src to dest
 * @dest: destination of the copied string
 * @src: source of the string to be copied to <dest>
 * Return: pointer to the updated string after copying (dest)
 */

char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}


/**
 * _strdup - allocate & return memory for a string duplicate
 * @str: string to return a memory to its duplicate
 * Return: memory to the string duplicate
*/
char *_strdup(char *str)
{
	char *ptr_alloc, *ptr_alloc_char;
	size_t len;

	if (!str)
		return (NULL);

	for (len = 0; str[len]; len++)
		;

	ptr_alloc = malloc(sizeof(char) * len + 1);
	if (!ptr_alloc)
		return (NULL);

	ptr_alloc_char = ptr_alloc;

	while (*str)
	{
		*ptr_alloc_char = *str;
		str++;
		ptr_alloc_char++;
	}
	*ptr_alloc_char = '\0';
	return (ptr_alloc);
}

/**
 * _strcmp - compares 2 strings
 * @s1: first string to be compared with
 * @s2: second string compared on/with first string
 * Return: 0 if equal, positive if s1 < s2, negative if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strlen - returns the lenth of a string
 * @s: Paremeter to count
 * Return: length.
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
