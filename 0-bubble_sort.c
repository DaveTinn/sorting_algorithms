#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t idx = 0; size_t val;

	if (array == NULL || size == 0)
	{
		return;
	}
	for (idx = 0; idx < size - 1; idx++)
	{
		for (val = 0; val < size - 1; val++)
		{
			if (array[val] > array[val + 1])
			{
				temp = array[val];
				array[val] = array[val + 1];
				array[val + 1] = temp;
				print_array(array, size);
			}
		}
	}
	idx++;
}
