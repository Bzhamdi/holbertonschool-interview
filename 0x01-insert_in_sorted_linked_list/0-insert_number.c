#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert_node in  listint_t list
 * @head: head of list
 *@number: number of node
 * Return: number of nodes
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *current;


	node = malloc(sizeof(listint_t));
	node->n = number;
	if (*head == NULL)
	{
	*head = node;
		return (*head);
	}
	current = *head;
	if (node->n < current->n)
	{
		node->next = *head;
		*head = node;
	}
	else
	{
		current = *head;
		while (current->next != NULL && current->next->n < node->n)
			current = current->next;
		node->next = current->next;
		current->next = node;
	}
	return (node);
}
