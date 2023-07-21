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
