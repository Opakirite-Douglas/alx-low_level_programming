#include "main.h"

/**
 * _memcpy - copy memory area
 * @dest: storage memory
 * @src: source memory
 * @n: number of byte
 *
 * Return: copied memory with updated n bytes
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int h = 0;
	int i = n;

	for (; h < i; h++)
	{
		dest[h] = src[h];
		n--;
	}
	return (dest);
}
