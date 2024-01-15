#include "main.h"

/**
 * _strlen - To return length of string
 * @s: The string
 * Return: length
 */

int _strlen(char *s)
{
	int longa = 0;

	while (*s != '\0')
	{
		longa++;
		s++;
	}
	return (longa);
}
