#include <stdio.h>
#include <string.h>

/*
 * String reversal (in-place)
 * --------------------------------------
 * Given a null-terminated string, reverse its characters in place.
 * The function swaps characters from the beginning and end,
 * moving toward the center until the string is fully reversed.
 * --------------------------------------
 * Worst-case performance O(n)
 * Best-case performance O(n)
 * Average performance O(n)
 * Worst-case space complexity O(1) iterative
 * */
void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0, end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "Hello";
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
