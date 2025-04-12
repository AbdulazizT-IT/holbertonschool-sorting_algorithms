#include "sort.h"

/**
 * selection_sort - Sorts an array using Selection Sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{

	size_t i, j, temp, minIdx;

	if (!array || size < 2)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		minIdx = i;
		for (j = i + 1 ; j < size ; j++)
		{
			if (array[j] < array[minIdx])
			{
				minIdx = j;
			}
		}
		if (minIdx != i)
		{
			temp = array[minIdx];
			array[minIdx] = array[i];
			array[i] = temp;

			print_array(array, size);
		}
	}
}
