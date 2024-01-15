#include "main.h"

/**
 * _strpbrk - Entry point for the program
 * @s: an input
 * @accept: an input
 * Return: Always 0 (Success)
 */

char *_strpbrk(char *s, char *accept)
{
	int m;

	while (*s)
	{
		for (m = 0; accept[m]; m++)
		{
			if (*s == accept[m])
				return (s);
		}
	s++;
	}

	return ('\0');
}
