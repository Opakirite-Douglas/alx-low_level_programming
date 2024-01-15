#include "main.h"

/**
 * char *_strcpy - To copy the string pointed to by src
 * @dest: where to copy to
 * @src: where to copy from
 * Return: value of the string
 */

char *_strcpy(char *dest, char *src)
{
	int g = 0;
	int h = 0;

	while (*(src + g) != '\0')
	{
		g++;
	}
	for ( ; h < g; h++)
	{
		dest[h] = src[h];
	}
	dest[g] = '\0';
	return (dest);
}
