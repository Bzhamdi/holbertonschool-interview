#include <stdio.h>
#include "lists.h"
/**
 * is_palindrome -  checks if a singly linked list is a palindrome.
 * @head: The head.
 * Return: 1 if palindrome and 0 if not
 */
int is_palindrome(listint_t **head)
{
	int len = -1, test = 1, x = 1, array[3000];

	while (*head)
	{
		len++;
		array[len] = (*head)->n;
		*head = (*head)->next;
	}
	while (--len > x  && test == 1)
	{
		if (array[x] != array[len])
			test = 0;
		++x;
	}
	return (test);
}
