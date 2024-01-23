#include "sort.h"
void heap_sort(int *array, size_t size)
{
	size_t idx;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (idx = size - 1; idx >= 0; idx--)
	{
		temp = array[0];
		array[0] = array[idx];
		array[idx] = temp;
	}
}
void swap_element(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
void heap_sift_down(int *array, size_t size, size_t lwst_idx, )
