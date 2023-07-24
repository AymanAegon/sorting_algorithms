#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - sorting array using Shell sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t h = 1, i, j;

	while (h * 3 + 1 < size)
	{
		h = h * 3 + 1;
	}
	while (h > 0)
	{
		for (j = h; j < size; j++)
		{
			temp = array[j];
			i = j;
			while (i >= h && array[i - h] >= temp)
			{
				array[i] = array[i - h];
				i -= h;
			}
			array[i] = temp;
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
