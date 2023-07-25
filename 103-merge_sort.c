#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merging_status - track merging from sublist to array
 * @a: sublist of the array to be merged
 * @begin: beginnig
 * @mid: middel
 * @end: end
 */
void merging_status(int *a, size_t begin, size_t mid, size_t end)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(a + begin, mid - begin);
	printf("[right]: ");
	print_array(a + mid, end - mid);
}
/**
 * merge - sorting array using merge sort algorithm
 * @array: array
 * @a: insorted array
 * @begin: beginning
 * @mid: middle
 * @end: ending
 */
void merge(int *array, int *a, size_t begin, size_t mid, size_t end)
{
	size_t i, j, k;

	i = begin;
	j = mid;
	k = begin;
	merging_status(a, begin, mid, end);
	while (i < mid && j < end)
	{
		if (a[i] < a[j])
		{
			array[k] = a[i];
			i++;
		}
		else
		{
			array[k] = a[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		array[k] = a[i];
		i++;
		k++;
	}
	while (j < end)
	{
		array[k] = a[j];
		k++;
		j++;
	}
}
/**
 * merge_sort_function - sorting array using Merge sort algorithm
 * @array: array to sort
 * @a: unsorted array
 * @begin: beginnig
 * @end: end
 */
void merge_sort_function(int *array, int *a, size_t begin, size_t end)
{
	size_t mid, i;

	if (end - begin < 2)
		return;
	mid = (end + begin) / 2;
	merge_sort_function(array, a, begin, mid);
	merge_sort_function(array, a, mid, end);
	merge(array, a, begin, mid, end);
	for (i = begin; i < end; i++)
		a[i] = array[i];
	printf("[Done]: ");
	print_array(array + begin, end - begin);
}
/**
 * merge_sort - sorting array using Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *a;
	size_t i;

	if (!array || size < 2)
		return;
	a = malloc(sizeof(int) * size);
	if (a == NULL)
		return;
	for (i = 0; i < size; i++)
		a[i] = array[i];
	merge_sort_function(array, a, 0, size);
}
