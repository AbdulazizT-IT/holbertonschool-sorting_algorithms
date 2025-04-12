#include "sort.h"
#include <stdio.h>

/**
* lomuto_partition - Lomuto partition scheme for quicksort
* @array: The array to be sorted
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the array
*
* Return: The index of the pivot after partitioning
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int temp;
int j;

for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}

if (array[i + 1] != array[high])
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}

return (i + 1);
}

/**
* quick_sort_recursive - Recursive helper function for quick_sort
* @array: The array to be sorted
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = lomuto_partition(array, low, high, size);

quick_sort_recursive(array, low, pi - 1, size); /* Left part */
quick_sort_recursive(array, pi + 1, high, size); /* Right part */
}
}

/**
* quick_sort - Function to sort an array using quicksort algorithm
* @array: The array to be sorted
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
