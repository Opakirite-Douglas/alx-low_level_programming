/*
 * File: 102-free_listint_safe.c
 * Auth: abayomi robert onawole
 */
#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list 
 */
size_t free_listint_safe(listint_t **h)
{
	size_t leen = 0;
	int diff;
	listint_t *temp;

	if (!h || !*h)
	return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			leen++;
		}
		else
	{
		free(*h);
		*h = NULL;
		leen++;
		break;
	}
	}

	*h = NULL;
	return (leen);
}


