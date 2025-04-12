#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index (pivot)
 * @size: Total size of the array (used for print_array)
 *
 * Return: Index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size); /* Print after each swap */
			}
			i++;
		}
	}

	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size); /* Final swap with pivot */
	}

	return (i); /* Return the index where pivot is placed */
}

/**
 * quick_sort_recursive - Recursive helper for quick_sort
 * @array: Array to be sorted
 * @low: Start index
 * @high: End index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size); /* Sort left */
		quick_sort_recursive(array, pivot + 1, high, size);/* Sort right */
	}
}

/**
 * quick_sort - Main quick sort function
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
