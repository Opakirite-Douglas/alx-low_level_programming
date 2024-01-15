#include "main.h"

/**
 * _strncpy - This program copy a string
 * @dest: an input
 * @src: an input
 * @n: an input
 *
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int y = 0;

	while (y < n && src[y] != '\0')
	{
		dest[y] = src[y];
		y++;
	}
	while (y < n)
	{
		dest[y] = '\0';
		y++;
	}
	return (dest);
}
