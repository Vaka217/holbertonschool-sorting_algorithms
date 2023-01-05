#include "sort.h"
#include <stdio.h>
#include "2-selection_sort.c"

/**
  * quick_sorts - sort an array with quick sort.
  * @array: Pointer to array to sort
  * @low: Lowest index
  * @high: Highest index
  * @size: Size of the array
  *
  */

void quick_sorts(int **array, size_t low, size_t high, size_t size)
{
	int part;

	if (low < high)
	{
		part = partition(*array, low, high, size);
		if (part == 0)
			part = high + 1;
		if (part == -1)
			return;
		quick_sorts(array, low, part - 1, size);
		quick_sorts(array, part + 1, high, size);
	}
}

/**
  * quick_sort - Acts like main function.
  * @array: Array to sort
  * @size: Size of the array
  *
  */

void quick_sort(int *array, size_t size)
{
	if (array && size > 0)
		quick_sorts(&array, 0, size - 1, size);
}

/**
  * partition - Sorts a certain partition with given indexs.
  * @array: Array to partitionate
  * @low: Lowest index
  * @high: Highest index
  * @size: Size of the array
  *
  * Return: The index of the pivot
  */

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	size_t j, i = low - 1, equal = 0;
	int pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
				swap_s(array, j, i, size);
		}
		if (array[j] == array[j + 1])
			equal++;
	}
	if (equal == size - 1)
		return (-1);
	if (array[high] != array[i + 1])
		swap_s(array, high, i + 1, size);
	return (i + 1);
}
