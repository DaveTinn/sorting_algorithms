#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t val, idx, j;
	int temp;

	if (array == NULL || size == 0)
	{
		return;
	}
	for (val = Knuth_sequence(size); val; val = (val - 1) / 3)
	{
		for (idx = val; idx < size; idx++)
		{
			temp = array[idx];
			for (j = idx; j > val - 1 && array[j - val] > temp; j -= val)
			{
				array[j] = array[j - val];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
/**
 * Knuth_sequence - Creates the gap
 * @size: Sze of the array
 *
 * Return: Initial gap
 */
size_t Knuth_sequence(size_t size)
{
	size_t h;

	h = 1;
	while (h < size)
	{
		h = h * 3 + 1;
	}
	return (h / 3);
}
