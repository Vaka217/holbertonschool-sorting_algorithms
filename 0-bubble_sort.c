#include "sort.h"
/**
 * bubble_sort - implements a bubble sort with recursion :)
 *
 *@array: array
 *@size: size of array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t status = 0, cnt;

	if (!array)
		return;

	for (cnt = 0; cnt < size - 1; cnt++)
	{
		if (array[cnt] > array[cnt + 1])
		{
			swap(array, cnt);
			print_array(array, size);
			status++;
		}
	}
	if (status == 0)
		return;
	bubble_sort(array, size);
}
/**
 * swap - swapm two elements of an array
 *
 *@array: array
 *@cnt: array counter
 */
void swap(int *array, size_t cnt)
{
	int tmp;

	tmp = array[cnt];
	array[cnt] = array[cnt + 1];
	array[cnt + 1] = tmp;
}
