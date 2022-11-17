#include "search.h"

/**
 * display_checked - Prints the checked nodes
 *
 * @checked_index: Index of the checked node
 * @checked_value: Value of the checked node
 */
void display_checked(size_t checked_index, int checked_value)
{
	printf("Value checked at index [%lu] = [%d]\n", checked_index, checked_value);
}

/**
 * display_between - Prints the nodes between the searched value
 *
 * @between_index: Index of the node between the searched value
 * @between_index_next: Index of the next node between the searched value
 */
void display_between(size_t between_index, size_t between_index_next)
{
	printf(
	    "Value found between indexes [%lu] and [%lu]\n",
	    between_index,
	    between_index_next);
}

/**
 * linear_skip - linear skip search algorithm
 *
 * @list: list to search in
 * @value: value to search for
 *
 * Return: pointer to the node containing the value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node;

	if (!list || list->n > value)
		return (NULL);

	for (node = list; node->express; node = node->express)
	{
		display_checked(node->express->index, node->express->n);
		if (node->express->n >= value)
		{
			display_between(node->index, node->express->index);
			break;
		}
	}

	if (!node->express)
	{
		for (list = node; list->next && list->n <= value; list = list->next)
			;
		display_between(node->index, list->index);
	}

	for (list = node; list != node->express; list = list->next)
	{
		display_checked(list->index, list->n);
		if (list->n == value)
			break;

		if (list->n > value)
			return (NULL);
	}

	return (list == node->express ? NULL : list);
}
