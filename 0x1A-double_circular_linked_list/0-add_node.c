#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * add_node_end - adds a new node at the end of double linked list
 * @list: pointer to a pointer of the start of the list
 * @str: the string to copy into the new node
 * Return: address of the new element or NULL if it fails
 */
List *add_node_end(List **list, char *str)
{
	if (!*list || !str)
	{
		return (NULL);
	}
	return (0);
}

/**
 * add_node_begin - adds a new node at the start of double linked list
 * @list: pointer to a pointer of the start of the list
 * @str: the string to copy into the new node
 * Return: address of the new element or NULL if it fails
 */
List *add_node_begin(List **list, char *str)
{
	if (!*list || !str)
	{
		return (NULL);
	}
	return (0);
}
