#include <stddef.h>
#include "clibx.h"

/*
 * Insertion sort
 * --------------------------------------
 * Sort an array arr[] of n elements by building the final sorted array
 * one element at a time. Each element is inserted into its correct position
 * within the sorted portion of the array.
 * Efficient for small or nearly sorted datasets.
 * --------------------------------------
 * Worst-case performance O(n^2)
 * Best-case performance O(n) - when array is already sorted
 * Average performance O(n^2)
 * Worst-case space complexity O(1)
 * --------------------------------------
 * https://en.wikipedia.org/wiki/Insertion_sort
 * */
void insertion_sort(int arr[], size_t size) {
	for (size_t i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main() {
	int arr[] = {12, 11, 13, 5, 6};
	insertion_sort(arr, ARRAY_SIZE(arr));
	print_int_array(arr, ARRAY_SIZE(arr));
	return 0;
}
