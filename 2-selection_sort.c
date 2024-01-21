#include "sort.h"
/**
 * selection_sort - function to sort an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t idx, val, low_idx;

	if (array == NULL || size == 0)
	{
		return;
	}
	for (idx = 0; idx < size - 1; idx++)
	{
		low_idx = idx;
		for (val = idx + 1; val < size; val++)
		{
			if (array[val] < array[low_idx])
			{
				low_idx = val;
			}
		}
		if (low_idx != idx)
		{
			temp = array[idx];
			array[idx] = array[low_idx];
			array[low_idx] = temp;
			print_array(array, size);
		}
	}
	idx++;
}
