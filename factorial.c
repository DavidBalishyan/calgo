#include <stddef.h>
#include "clibx.h"

/*
 * Factorial (iterative)
 * --------------------------------------
 * Computes n! = n * (n-1) * (n-2) * ... * 1
 * By definition, 0! = 1.
 * --------------------------------------
 * Worst-case performance O(n)
 * Best-case performance O(1) - for n = 0 or n = 1
 * Average performance O(n)
 * Worst-case space complexity O(1)
 * --------------------------------------
 * https://en.wikipedia.org/wiki/Factorial
 * */
int factorial_iterative(int n) {
	if (n < 0) return -1;
	int result = 1;
	for (int i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}

/*
 * Factorial (recursive)
 * --------------------------------------
 * Computes n! using recursion: n! = n * (n-1)!
 * Base cases: 0! = 1, 1! = 1
 * --------------------------------------
 * Worst-case performance O(n)
 * Best-case performance O(1) - for n = 0 or n = 1
 * Average performance O(n)
 * Worst-case space complexity O(n) - recursion stack depth
 * --------------------------------------
 * https://en.wikipedia.org/wiki/Factorial
 * */
int factorial_recursive(int n) {
	if (n < 0) return -1;
	if (n <= 1) return 1;
	return n * factorial_recursive(n - 1);
}

int main() {
	PRINT(factorial_iterative(5));
	PRINT(factorial_recursive(5));
	return 0;
}
