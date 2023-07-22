#include "sort.h"

/**
 * selection_sort - sorts an array integers in ascending order
 * using the selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int x;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			x = array[i];
			array[i] = array[min];
			array[min] = x;
			print_array(array, size);
		}
	}
}
