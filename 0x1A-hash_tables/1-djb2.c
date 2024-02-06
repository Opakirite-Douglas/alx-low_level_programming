#include "hash_tables.h"

/**
 * hash_djb2 - This func is the Hash function that
 * implements the djb2 algorithm.
 *
 * @str: This is the string to hash.
 *
 * Return: The calculated hash.
 *
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int see;

	hash = 5381;
	while ((see = *str++))
		hash = ((hash << 5) + hash) + see;

	return (hash);
}
