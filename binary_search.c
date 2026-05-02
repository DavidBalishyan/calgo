#include <stddef.h>
#include "clibx.h"

/*
 * Binary search
 * --------------------------------------
 * Given a sorted array arr[] of n elements, find the index of a target value x.
 * The algorithm repeatedly divides the search interval in half.
 * Returns the index of the target if found, or -1 if not found.
 * --------------------------------------
 * Worst-case performance O(log n)
 * Best-case performance O(1)
 * Average performance O(log n)
 * Worst-case space complexity O(1) iterative
 * --------------------------------------
 * Requirement: The input array MUST be sorted in ascending order.
 * https://en.wikipedia.org/wiki/Binary_search_algorithm
 * */
clibx_bool binary_search(int arr[], int target, size_t size) {
	size_t left = 0;
	size_t right = size - 1;

	while (left <= right) {
		size_t mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return clibx_false;
}

int main() {
	int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
	int result = binary_search(arr, 7, ARRAY_SIZE(arr));
	if(result == clibx_false) {
		CLIBX_PRINT_BOOL(result);
	}else {
		PRINT(result);
	}
	return 0;
}
