#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: head node our list
 * Return: return 0 if it is not a palindrome, otherwise 1 if it is.
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int i = 0, j, array[2048], limit;

	if (*head == NULL || head == NULL)
		return (1);

	current = *head;
	while (current)
	{
		array[i] = current->n;
		current = current->next;
		i++;
	}

	limit = (i % 2 == 0) ? i / 2 : (i + 1) / 2;

	for (j = 0; j < limit; j++)
	{
		if (array[j] != array[i - 1 - j])
			return (0);
	}

	return (1);
}