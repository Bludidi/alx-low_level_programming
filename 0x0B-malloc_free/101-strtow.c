#include "main.h"
#include <stdlib.h>

/**
 * strtow - function to split string into words
 * @str: input string of words
 *
 * Return: double pointer to array of words
 */

char **strtow(char *str)
{
	int i = 0;
	int j = 0;
	int index = 0;
	int words = 1;
	char **array;

	if (str == 0)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			words++;
	}
	array = (char **) malloc(words * sizeof(char *));
	if (array == '\0')
		return (0);
	for (i = 0; i < words; i++)
	{
		for (j = 0; str[j] != ' '; j++)
			continue;
		j++;
		array[i] = (char *) malloc((j * sizeof(char)) + 1);
		if (array[i] == '\0')
		{
			for (; i >= 0; i++)
				free(array[i]);
			free(array);
			return (0);
		}
	}
	for (i = 0; i < words; i++)
	{
		for (j = 0; str[j] != ' '; j++, index++)
			array[i][index] = str[j];
		array[i][index] = '\0';
		index++;
	}
	return (array);
}
