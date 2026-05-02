#include <stddef.h>
#include "clibx.h"

/*
 * Quick sort (partition helper)
 * --------------------------------------
 * Partitions the array around a pivot element (last element chosen).
 * Elements smaller than pivot go to the left, larger go to the right.
 * Returns the final index of the pivot element.
 * */
static int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			SWAP(arr[i], arr[j]);
		}
	}
	SWAP(arr[i + 1], arr[high]);
	return i + 1;
}

/*
 * Quick sort (recursive helper)
 * --------------------------------------
 * Recursively sorts the sub-arrays before and after the pivot.
 * */
static void quick_sort_recursive(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quick_sort_recursive(arr, low, pi - 1);
		quick_sort_recursive(arr, pi + 1, high);
	}
}

/*
 * Quick sort
 * --------------------------------------
 * Sort an array arr[] of n elements using the divide-and-conquer approach.
 * Selects a pivot element, partitions the array around it, then recursively
 * sorts the sub-arrays on each side.
 * --------------------------------------
 * Worst-case performance O(n^2) - rare, occurs with poor pivot choice
 * Best-case performance O(n log n)
 * Average performance O(n log n)
 * Worst-case space complexity O(log n) - due to recursion stack
 * --------------------------------------
 * In-place sort, not stable.
 * https://en.wikipedia.org/wiki/Quicksort
 * */
void quick_sort(int arr[], size_t size) {
	if (size < 2) return;
	quick_sort_recursive(arr, 0, size - 1);
}

int main() {
	int arr[] = {10, 7, 8, 9, 1, 5};
	quick_sort(arr, ARRAY_SIZE(arr));
	print_int_array(arr, ARRAY_SIZE(arr));
	return 0;
}
