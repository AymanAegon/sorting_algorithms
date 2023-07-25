#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *swap - swap two nodes*
 *
 *@list: The array to be sorted
 *@temp: The temp node to be sorted
 *@head: The head of the list
 */
void swap(listint_t **list, listint_t *temp, listint_t *head)
{
	if (temp->prev)
		temp->prev->next = head;
	if (head->next)
		head->next->prev = temp;

	temp->next = head->next;
	head->prev = temp->prev;
	temp->prev = head;
	head->next = temp;

	if (!head->prev)
		*list = head;
}
/**
 * cocktail_sort_list - sorting list using cocktail shaker sort algorithm
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int b;

	if (list == NULL || *list == NULL)
		return;
	node = *list;
	while (1)
	{
		b = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				swap(list, node, node->next);
				print_list(*list);
				b = 1;
			}
			else
				node = node->next;
		}
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				swap(list, node->prev, node);
				print_list(*list);
				b = 1;
			}
			else
				node = node->prev;
		}
		if (b == 0)
			break;
	}
}
