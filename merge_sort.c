#include <stddef.h>
#include <stdlib.h>
#include "clibx.h"

/*
 * Merge (helper function)
 * --------------------------------------
 * Merges two sorted subarrays arr[l..m] and arr[m+1..r] into a single
 * sorted subarray. Uses temporary storage during the merge process.
 * */
static void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L = NEW_ARRAY(int, n1);
	int *R = NEW_ARRAY(int, n2);

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}

	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];

	FREE(L);
	FREE(R);
}

/*
 * Merge sort (recursive helper)
 * --------------------------------------
 * Recursively divides the array into halves until subarrays of size 1
 * are reached, then merges them back together in sorted order.
 * */
static void merge_sort_recursive(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		merge_sort_recursive(arr, l, m);
		merge_sort_recursive(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

/*
 * Merge sort
 * --------------------------------------
 * Sort an array arr[] of n elements using the divide-and-conquer approach.
 * Recursively splits the array in half, sorts each half, then merges them.
 * Guarantees O(n log n) performance regardless of input order.
 * --------------------------------------
 * Worst-case performance O(n log n)
 * Best-case performance O(n log n)
 * Average performance O(n log n)
 * Worst-case space complexity O(n) - requires temporary array for merging
 * --------------------------------------
 * Stable sort.
 * https://en.wikipedia.org/wiki/Merge_sort
 * */
void merge_sort(int arr[], size_t size) {
	if (size < 2) return;
	merge_sort_recursive(arr, 0, size - 1);
}

int main() {
	int arr[] = {38, 27, 43, 3, 9, 82, 10};
	merge_sort(arr, ARRAY_SIZE(arr));
	print_int_array(arr, ARRAY_SIZE(arr));
	return 0;
}
