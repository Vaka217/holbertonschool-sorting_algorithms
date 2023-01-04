#include "sort.h"
#include <stdio.h>
#include "2-selection_sort.c"
/**
  *
  */

void quick_sorts(int **array, size_t low, size_t high)
{
	size_t part;

	if (low < high)
	{
		part = partition(*array, low, high);
		if (part == 0)
			part = high + 1;
		print_array(*array, 10);
		quick_sorts(array, low, part - 1);
		quick_sorts(array, part + 1, high);
	}
}

void quick_sort(int *array, size_t size)
{
	quick_sorts(&array, 0, size - 1);
}
size_t partition(int *array, size_t low, size_t high)
{
	size_t j, i = low - 1;
	int pivot = array[high], tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
	}
	swap_s(array, high, i + 1);
	return (i + 1);
}
