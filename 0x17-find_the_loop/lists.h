#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

listint_t *find_listint_loop(listint_t *head);
listint_t *add_nodeint(listint_t **node, int value);
void free_listint_safe(listint_t **node);
void print_listint_safe(listint_t *node);

#endif
