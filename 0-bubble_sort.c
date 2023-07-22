#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int x, b = 1;

	if (size < 2)
		return;
	while (b == 1)
	{
		b = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				x = array[i];
				array[i] = array[i + 1];
				array[i + 1] = x;
				b = 1;
				print_array(array, size);
			}
		}
	}
}
