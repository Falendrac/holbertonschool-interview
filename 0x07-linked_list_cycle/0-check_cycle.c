#include "lists.h"

/**
 * check_cycle - Check if the linked list have a cycle
 *
 * @list: The linked list
 *
 * Return: 0 if there is no cycle, 1 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *current = list, *search = list;

	while (current != NULL && search && search->next)
	{
		current = current->next;
		search = search->next->next;

		if (search == current)
			return (1);
	}

	return (0);
}