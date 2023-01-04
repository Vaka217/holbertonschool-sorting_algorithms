#include "sort.h"
/**
 * selection_sort - sort an array by selection (min to max)
 *
 *@array: one array
 *@size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t cnt, cnt2, small;

	for (cnt = 0; cnt < (size - 1); cnt++)
	{
		small = cnt;
		for (cnt2 = (cnt + 1); cnt2 < size; cnt2++)
		{
			if (array[cnt2] < array[small])
				small = cnt2;
		}

		if (small != cnt)
		{	
			swap_s(array, small, cnt, size);
		}
	}
}
/**
 *swap_s - swap two elements of an array
 *
 *@array: array
 *@small: smallest value on the array
 *@cnt: counter
 *@size: array size
 */
void swap_s(int *array, size_t small, size_t cnt, size_t size)
{
	int tmp;

	tmp = array[cnt];
	array[cnt] = array[small];
	array[small] = tmp;
	print_array(array, size);
}
