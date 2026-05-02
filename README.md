# Calgo - C Algorithm Implementations

A collection of common algorithm implementations in C, each documented with complexity analysis and usage examples.

## Utilities

All algorithms use the `clibx.h` header, which provides utility macros and functions including:
- Array helpers (`ARRAY_SIZE`, `print_int_array`, etc.)
- Math macros (`MIN`, `MAX`, `ABS`, etc.)
- Memory helpers (`NEW`, `FREE`, `SWAP`, etc.)
- Debug/logging tools (`LOG`, `ERROR`, `ASSERT`, etc.)
- String utilities (`STREQ`, `strtrim`, `strsplit`, etc.)

## Algorithms

### Search Algorithms

| Algorithm | File | Best | Average | Worst | Space |
|-----------|------|------|---------|-------|-------|
| Linear Search | `linear_search.c` | O(1) | O(n) | O(n) | O(1) |
| Binary Search | `binary_search.c` | O(1) | O(log n) | O(log n) | O(1) |

### Sorting Algorithms

| Algorithm | File | Best | Average | Worst | Space | Stable |
|-----------|------|------|---------|-------|-------|--------|
| Bubble Sort | `bubble_sort.c` | O(n) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | Yes |
| Selection Sort | `selection_sort.c` | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | No |
| Insertion Sort | `insertion_sort.c` | O(n) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | Yes |
| Quick Sort | `quick_sort.c` | O(n log n) | O(n log n) | O(n<sup>2</sup>) | O(log n) | No |
| Merge Sort | `merge_sort.c` | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |

### Math Algorithms

| Algorithm | File | Best | Average | Worst | Space |
|-----------|------|------|---------|-------|-------|
| Fibonacci (iterative) | `fibonacci.c` | O(1) | O(n) | O(n) | O(1) |
| Fibonacci (recursive) | `fibonacci.c` | O(1) | O(2^n) | O(2^n) | O(n) |
| Factorial (iterative) | `factorial.c` | O(1) | O(n) | O(n) | O(1) |
| Factorial (recursive) | `factorial.c` | O(1) | O(n) | O(n) | O(n) |

### String Algorithms

| Algorithm | File | Best | Average | Worst | Space |
|-----------|------|------|---------|-------|-------|
| Reverse String | `reverse_string.c` | O(n) | O(n) | O(n) | O(n) |

## Building and Running

Each algorithm file contains a `main()` function with a usage example. Compile and run individually:

```bash
gcc -o binary_search binary_search.c && ./binary_search
gcc -o quick_sort quick_sort.c && ./quick_sort
gcc -o fibonacci fibonacci.c && ./fibonacci
```

## Algorithm Selection Guide

- **Searching**: Use binary search on sorted data, linear search otherwise
- **Sorting small arrays**: Insertion sort performs well on small or nearly-sorted data
- **Sorting general purpose**: Quick sort for most cases, merge sort when stability is required
- **Fibonacci**: Always prefer the iterative version; recursive is exponential time
