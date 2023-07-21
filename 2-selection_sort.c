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
	size_t i,j;
	int x, b = 0;

	for (i = 0; i < size-1; i++)
	{
		for (j = i+1; j < size; j++)
		{
			if(array [i] > array [j])
			{
				x = array[i];
				array[i] = array[j];
				array[j] = x;
				b = 1;
			}
		}
		if (b == 1)
			print_array(array, size);
		b = 0;
	}
}
