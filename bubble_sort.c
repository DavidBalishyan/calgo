#include <stddef.h>
#include "clibx.h"

/*
 * Bubble sort
 * --------------------------------------
 * Sort an array arr[] of n elements by repeatedly swapping adjacent
 * elements that are in the wrong order. Larger elements "bubble" to the
 * end of the array with each pass.
 * --------------------------------------
 * Worst-case performance O(n^2)
 * Best-case performance O(n) - when array is already sorted
 * Average performance O(n^2)
 * Worst-case space complexity O(1)
 * --------------------------------------
 * https://en.wikipedia.org/wiki/Bubble_sort
 * */
void bubble_sort(int arr[], size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		clibx_bool swapped = clibx_false;
		for (size_t j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				SWAP(arr[j], arr[j + 1]);
				swapped = clibx_true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}

int main() {
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	bubble_sort(arr, ARRAY_SIZE(arr));
	print_int_array(arr, ARRAY_SIZE(arr));
	return 0;
}
