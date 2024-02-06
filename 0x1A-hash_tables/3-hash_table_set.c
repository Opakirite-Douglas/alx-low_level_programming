#include "hash_tables.h"

/**
 * hash_table_set - This func will update an element in a hash table.
 *
 * @ht: Just simply a pointer to the hash table.
 *
 * @key: Represents key to update and can't be empty string.
 *
 * @value: Represents value associated with key.
 *
 * Return: 0(FAILURE) else 1(SUCCESS)
 *
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *value_copy;
	unsigned long int index, eye;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (eye = index; ht->array[eye]; eye++)
	{
		if (strcmp(ht->array[eye]->key, key) == 0)
		{
			free(ht->array[eye]->value);
			ht->array[eye]->value = value_copy;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
