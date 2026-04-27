#include <stdlib.h>
#include <string.h>
#include "clibx.h"

/*
 * String reversal
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
str reverseString(char string[]) {
    str copy = malloc(strlen(string) + 1);
    strcpy(copy, string);
    int length = strlen(copy);
    int start = 0, end = length - 1;
    char temp;

    while (start < end) {
        temp = copy[start];
        copy[start] = copy[end];
        copy[end] = temp;
        start++;
        end--;
    }
    return copy;
}

int main() {
    char str[] = "Hello";
    PRINT(reverseString(str));
    LOG("%s\n", str);
    return 0;
}
