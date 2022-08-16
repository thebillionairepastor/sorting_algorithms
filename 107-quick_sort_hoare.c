#include "sort.h"

/**
 * hoare_partition - hoare partition scheme using rightmost index as pivot;
 * other pivot implementations exist, with some with greater efficiency: see
 * peudocode below function defs for middle or low pivot schema
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 * return: new index at which to start new recursive partition
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (true)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * hoare_quicksort - recursively sorts array of integers by separating into two
 * partitions, using hoare quick sort
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 */
void hoare_quicksort(int *array, size_t low, size_t high, size_t size)
{
	size_t border;

	if (low < high)
	{
		border = hoare_partition(array, low, high, size);
		hoare_quicksort(array, low, border, size);
		hoare_quicksort(array, border + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending order using a quick
 * sort, hoare partition scheme alogrithm
 * @array: array of values to be printed
 * @size: number of elements in array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort(array, 0, size - 1, size);
}

/*
 * lomuto pseudo:
 *
 * algorithm quicksort(a, lo, hi) is
 *   if lo < hi then
 *       p := partition(a, lo, hi)
 *       quicksort(a, lo, p - 1)
 *       quicksort(a, p + 1, hi)
 *
 * algorithm partition(a, lo, hi) is
 *   pivot := a[hi]
 *   i := lo
 *   for j := lo to hi do
 *       if a[j] < pivot then
 *           swap a[i] with a[j]
 *           i := i + 1
 *   swap a[i] with a[hi]
 *   return i
 *
 * hoare pseudo:
 *
 * algorithm quicksort(a, lo, hi) is
 *   if lo < hi then
 *       partition_border := partition(a, lo, hi)
 *       quicksort(a, lo, partition_border)
 *       quicksort(a, partition_border + 1, hi)
 *
 * (using middle pivot):
 *
 * algorithm partition(a, lo, hi) is
 *    pivot := a[(hi + lo) / 2] // depends on rounding towards 0, as in c
 *   i := lo
 *   j := hi
 *   loop forever
 *       while a[i] < pivot
 *           i := i + 1
 *       while a[j] > pivot
 *           j := j - 1
 *       if i  j then
 *           return j
 *       swap a[i] with a[j]
 *       i := i + 1
 *       j := j - 1
 *
 * (using first pivot):
 *
 * algorithm partition(a, lo, hi) is
 *   pivot := a[lo]
 *   i := lo - 1
 *   j := hi + 1
 *   loop forever
 *       do
 *           i := i + 1
 *       while a[i] < pivot
 *	do
 *           j := j - 1
 *       while a[j] > pivot
 *       if i >= j then
 *           return j
 *       swap a[i] with a[j]
 */
