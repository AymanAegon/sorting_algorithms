#include "sort.h"

/**
 * partition - rerange the array and sets the pindex
 *
 * @arr: The pased array
 * @start: The Start of list
 * @end: The End of list
 * @size: the size of the array
 * Return: int
 */
int partition(int *arr, int start, int end, size_t size)
{
	int pivot = arr[end];
	int pindex = start - 1;
	int i, temp;

	for (i = start; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			pindex++;
			temp = arr[i];
			arr[i] = arr[pindex];
			arr[pindex] = temp;

			if (pindex != i)
			{
				print_array(arr, size);
			}
		}
	}
	temp = arr[end];
	arr[end] = arr[pindex + 1];
	arr[pindex + 1] = temp;
	if (end != (pindex + 1))
	{
		print_array(arr, size);
	}

	return (pindex + 1);
}

/**
 * quick_sort_helper - rerange the array and sets the pindex
 *
 * @array: The pased array
 * @start: The Start of list
 * @end: The End of list
 * @size: the size of the array
 * Returns: void
 */
void quick_sort_helper(int *array, int start, int end, size_t size)
{
	int pindex;

	if (start < end)
	{
		pindex = partition(array, start, end, size);
		quick_sort_helper(array, start, pindex - 1, size);
		quick_sort_helper(array, pindex + 1, end, size);

	}
}

/**
 * quick_sort - Prints a list of integers
 *
 * @array: The list to be printed
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
