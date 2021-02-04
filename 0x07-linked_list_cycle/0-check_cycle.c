#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: list.
 * Return: 1 is a cycle else 0.
 */

int check_cycle(listint_t *list)
{
listint_t *l1 = list;
listint_t *l2 = list;

if (!list)
return (0);
while (l1 && (l1 = l1->next) && l2)
{
if (l1 == l2)
return (1);
l1 = l1->next;
l2 = l2->next;
}
return (0);
}
