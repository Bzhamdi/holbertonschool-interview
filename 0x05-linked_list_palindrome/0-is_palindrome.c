#include "lists.h"
#include <stdio.h>
/**
 * get_nodeint_at_index - return the nth node of a linked list.
 * @head: the head of the list
 * @index: the index of the node
 * Return: nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);
	for (i = 0; i < index && head != NULL; i++)
	{
		head = head->next;
	}
	if (head)
		return (head);

	return (NULL);
}
/**
 * is_palindrome -  checks if a singly linked list is a palindrome.
 * @head: The head.
 * Return: 1 if palindrome and 0 if not
 */

int is_palindrome(listint_t **head)
{
	unsigned int l, i;
	listint_t *first, *last, *len;

	if (*head == NULL)
		return (1);
	if (head == NULL)
		return (1);
	len = *head;
	while (len->next != NULL)
	{
		len = len->next;
		l++;
	}
	if (l == 1)
		return (1);

	for (i = 0; i < (l / 2); i++)
	{
		first = get_nodeint_at_index(*head, i);
		last = get_nodeint_at_index(*head, (l - 1 - i));
		if (first->n != last->n)
			return (0);
	}

	return (1);
}

