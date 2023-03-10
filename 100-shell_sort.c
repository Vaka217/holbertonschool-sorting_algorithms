#include "sort.h"

/**
  * shell_sort - sorts an array of integers using the Shell sort.
  * @array: Array of integers to sort
  * @size: Size of the array
  */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (!array | (size < 2))
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
