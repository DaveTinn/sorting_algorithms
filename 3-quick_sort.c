#include "sort.h"
/**
 * swap_array - function to swap array of integers
 * @array: pointer to the array of integers
 * @size: size of array
 * @a: pointer to first element in the array to be swapped
 * @b: pointer to second element in the array to be swapped
 * Return: Nothing
 */
void swap_array(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}
/**
 * quick_sort - function to sort the array of integers in ascending order
 * @array: pointer to the array of integers
 * @size: size of array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}
	quicksorter(array, size, 0, size - 1);
}
/**
 * Lomuto_partitioner - function to partition the array of integers
 * @array: pointer to the array of integers
 * @size: size of array
 * @start_idx: starting index of partition
 * @end_idx: ending index of partition
 *
 * Return: pivot index
 */
size_t Lomuto_partitioner(int *array, size_t size, int start_idx, int end_idx)
{
	int piv_idx;
	int piv_val;

	piv_val = array[end_idx];
	for (piv_idx = start_idx; start_idx < end_idx; start_idx++)
	{
		if (array[start_idx] < piv_val)
		{
			swap_array(array, size, &array[start_idx], &array[piv_idx]);
			piv_idx++;
		}
	}
	swap_array(array, size, &array[piv_idx], &array[end_idx]);
	return (piv_idx);
}
/**
 * quicksorter - Sorts the array of integers in ascending order
 * @array: pointer to the array of integers
 * @size: size of array
 * @start_idx: start index of the array
 * @end_idx: end index of the array
 *
 * Return: Nothing
 */
void quicksorter(int *array, size_t size, int start_idx, int end_idx)
{
	size_t piv_idx;

	if (start_idx < end_idx)
	{
		piv_idx = Lomuto_partitioner(array, size, start_idx, end_idx);
		quicksorter(array, size, start_idx, piv_idx - 1);
		quicksorter(array, size, piv_idx + 1, end_idx);
	}
}
