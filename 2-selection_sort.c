#include "sort.h"

/**
  *
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
			swap_s(array, small, cnt);
			print_array(array, size);
		}
	}
}
void swap_s(int *array, size_t small, size_t cnt)
{
	int tmp;

	tmp = array[cnt];
	array[cnt] = array[small];
	array[small] = tmp;
}
