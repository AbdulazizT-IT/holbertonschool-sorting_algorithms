#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array in ascending order using Bubble sort.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, j, temp;
	int swapped;

	for (i = 0 ; i < size - 1 ; i++)
	{
		swapped = 0;
		for (j = 0 ; j < size - i - 1 ; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
				swapped = 1;
			}

		}
		if (!swapped)
			break;
	}
}
