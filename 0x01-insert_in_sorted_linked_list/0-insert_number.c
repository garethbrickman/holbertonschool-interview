#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - insets a number into a sorted listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: number to be included in list
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *new;

	/* NULL head check, error */
	if (!head)
		return (NULL);

	/* empty list check, insert new node automatically*/
	if (!(*head))
		return (add_nodeint_end(head, number));

	/* copy head to be able to move through list */
	current = *head;

	/* search for where n > number */
	while (current->next)
	{
		if (current->next->n >= number)
		{
			/* insert new node into this position */
			new = malloc(sizeof(listint_t));
			if (!new)
				return (NULL);
			new->n = number;
			new->next = current->next;
			current->next = new;
			return (new);
		}
		/* end of list reached */
		else if (!current->next->next)
			return (add_nodeint_end(head, number));
		current = current->next;
	}
	/* workaround for non-void function error */
	return (NULL);
}
