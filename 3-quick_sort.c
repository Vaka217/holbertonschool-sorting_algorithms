#include "sort.h"
#include <stdio.h>
#include "2-selection_sort.c"
/**
  *
  */

void quick_sorts(int **array, size_t low, size_t high, size_t size)
{
	size_t part;

	if (low < high)
	{
		part = partition(*array, low, high, size);
		if (part == 0)
			part = high + 1;
		quick_sorts(array, low, part - 1, size);
		quick_sorts(array, part + 1, high, size);
	}
}

void quick_sort(int *array, size_t size)
{
	quick_sorts(&array, 0, size - 1, size);
}
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	size_t j, i = low - 1;
	int pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
				swap_s(array, j, i, size);
		}
	}
	if (array[high] != array[i + 1])
		swap_s(array, high, i + 1, size);
	return (i + 1);
}
