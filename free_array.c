#include "shell.h"

/**
 * free_array - a function that frees the memmory allocated to an array
 * @arr: the array to be freed
 *
 * Return: void
 */
void free_array(char **arr)
{
	if (!arr)
		return;

	for (int i = 0; arr[i] != NULL; i++)
		free(arr[i]);

	free(arr);
}
