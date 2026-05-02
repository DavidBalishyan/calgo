#include <stddef.h>
#include "clibx.h"

/*
 * Selection sort
 * --------------------------------------
 * Sort an array arr[] of n elements by repeatedly finding the minimum
 * element from the unsorted portion and placing it at the beginning.
 * Maintains two subarrays: sorted and unsorted.
 * --------------------------------------
 * Worst-case performance O(n^2)
 * Best-case performance O(n^2)
 * Average performance O(n^2)
 * Worst-case space complexity O(1)
 * --------------------------------------
 * https://en.wikipedia.org/wiki/Selection_sort
 * */
void selection_sort(int arr[], size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		size_t min_idx = i;
		for (size_t j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			SWAP(arr[i], arr[min_idx]);
		}
	}
}

int main() {
	int arr[] = {64, 25, 12, 22, 11};
	selection_sort(arr, ARRAY_SIZE(arr));
	print_int_array(arr, ARRAY_SIZE(arr));
	return 0;
}
