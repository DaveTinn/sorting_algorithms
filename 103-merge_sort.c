#include "sort.h"
/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *sub_arr;
	size_t idx;

	if (array == NULL || size < 2)
	{
		return;
	}
	sub_arr = malloc(sizeof(int) * size);
	if (sub_arr == NULL)
	{
		return;
	}
	for (idx = 0; idx < size; idx++)
	{
		sub_arr[idx] = array[idx];
	}
	merge_top_down(sub_arr, 0, size, array);
	free(sub_arr);
}
/**
 * merge_top_down - Recursively divides and merges sub-arrays in a top-down way
 * @array: Pointer to the original array
 * @start_idx: Start index of the sub-array
 * @end_idx: End index of the sub-array
 * @sub_arr: Temporary array to assist in merging
 * Return: Nothing
 */
void merge_top_down(int *array, size_t start_idx, size_t end_idx, int *sub_arr)
{
	size_t mid_idx;

	mid_idx = (start_idx + end_idx) / 2;
	if (end_idx - start_idx < 2)
	{
		return;
	}
	merge_top_down(sub_arr, start_idx, mid_idx, array);
	merge_top_down(sub_arr, mid_idx, end_idx, array);
	merge(array, start_idx, end_idx, sub_arr);
}
/**
 * merge - Merges two sub-arrays of integers
 * @array: Pointer to the original array
 * @start_idx: Start index of the sub-array to be maerged
 * @end_idx: End index of the sub-array to be maerged
 * @sub_arr: Temporary array for storing merged sub-array
 * Return: Nothing
 */
void merge(int *array, size_t start_idx, size_t end_idx, int *sub_arr)
{
	size_t idx, mid_idx, i, d;

	idx = start_idx;
	mid_idx = (start_idx + end_idx) / 2;
	i = mid_idx;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start_idx, mid_idx - start_idx);
	printf("[right]: ");
	print_array(array + mid_idx, end_idx - mid_idx);
	for (d = start_idx; d < end_idx; d++)
	{
		if (idx < mid_idx && (i >= end_idx || array[idx] <= array[i]))
		{
			sub_arr[d] = array[idx++];
		}
		else
		{
			sub_arr[d] = array[i++];
		}
	}
	printf("[Done]: ");
	print_array(sub_arr + start_idx, end_idx - start_idx);
}
