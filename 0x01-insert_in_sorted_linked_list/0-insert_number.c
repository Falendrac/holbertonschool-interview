#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list.
 *
 * @head: The pointer linked list
 * @number: The number we add in the linked list
 * Return: Null if failed, otherwise the adress of the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode, *current = *head;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = number;

	if (*head == NULL || number < (*head)->n)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		while (current->next && current->next->n < number)
			current = current->next;
		newNode->next = current->next;
		current->next = newNode;
	}

	return (newNode);
}
