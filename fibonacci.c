#include <stddef.h>
#include "clibx.h"

/*
 * Fibonacci (iterative)
 * --------------------------------------
 * Computes the nth Fibonacci number using iteration.
 * The Fibonacci sequence is defined as:
 *   F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n > 1
 * Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 * --------------------------------------
 * Worst-case performance O(n)
 * Best-case performance O(1) - for n = 0 or n = 1
 * Average performance O(n)
 * Worst-case space complexity O(1)
 * --------------------------------------
 * https://en.wikipedia.org/wiki/Fibonacci_number
 * */
int fibonacci_iterative(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;

	int a = 0, b = 1;
	for (int i = 2; i <= n; i++) {
		int temp = a + b;
		a = b;
		b = temp;
	}
	return b;
}

/*
 * Fibonacci (recursive)
 * --------------------------------------
 * Computes the nth Fibonacci number using recursion.
 * Simple but inefficient due to repeated calculations.
 * --------------------------------------
 * Worst-case performance O(2^n)
 * Best-case performance O(1) - for n = 0 or n = 1
 * Average performance O(2^n)
 * Worst-case space complexity O(n) - recursion stack depth
 * --------------------------------------
 * Not recommended for large n. Use fibonacci_iterative instead.
 * */
int fibonacci_recursive(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

/*
 * Fibonacci (array generator)
 * --------------------------------------
 * Generates the first n Fibonacci numbers and stores them in arr[].
 * Caller must ensure arr has sufficient space (at least n elements).
 * --------------------------------------
 * Worst-case performance O(n)
 * Worst-case space complexity O(1) - excluding output array
 * */
void fibonacci_array(int arr[], int n) {
	if (n <= 0) return;
	arr[0] = 0;
	if (n == 1) return;
	arr[1] = 1;
	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

int main() {
	PRINT(fibonacci_iterative(10));
	PRINT(fibonacci_recursive(10));

	int arr[10];
	fibonacci_array(arr, ARRAY_SIZE(arr));
	print_int_array(arr, ARRAY_SIZE(arr));
	return 0;
}
