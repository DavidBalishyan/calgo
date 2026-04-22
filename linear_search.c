#include <stddef.h>
#include <stdio.h>
#include "clibx.h"

/*
 * Linear search
 * --------------------------------------
 * Given an array, arr[] of n integers, and an integer element x,
 * find whether element x is present in the array.
 * Return the index of the first occurrence of x in the array, or -1 if it doesn't exist.
 * --------------------------------------
 * Worst-case performance O(n)
 * Best-case performance O(1)
 * Average performance O(n)
 * Worst-case space complexity O(1) iterative
 * --------------------------------------
 * https://en.wikipedia.org/wiki/Linear_search
 * */
clibx_bool linear_search(int arr[], int target, size_t size) {
	for (int i = 0; i < size; i++) {
		if(arr[i] == target) {
			return i;
		}
	}
	return clibx_false;
}

int main() {
	int arr[] = {1, 2, 3, 4};
	int result = linear_search(arr, 3, ARRAY_SIZE(arr));
	return 0;
}
