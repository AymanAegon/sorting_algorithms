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

