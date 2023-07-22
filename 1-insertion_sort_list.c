#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of int in ascending order
 * using the Insertion sort algorithm
 *
 * @list: The array to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *head;

	head = *list;
	if (!head || !head->next)
		return;
	while (head)
	{
		while (head->prev)
		{
			temp = head->prev;
			if (temp->n > head->n)
			{
				swap(list, temp, head);
				print_list(*list);
			}
			else
			{
				break;
			}
		}
		head = head->next;
	}
}
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
