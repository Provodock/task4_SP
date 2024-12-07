#ifndef SORT
#define SORT
#include "stringProcessor.h"
#include <string.h>

inline void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(char** arr, size_t length) {
    if (length <= 1) {
        return;
    }

    size_t piv = 0;
    const size_t last = length - 1;

    // Optimize pivot selection by using median-of-three
    size_t mid = length / 2;
    if (strcmp(arr[0], arr[mid]) > 0) {
        swap(&arr[0], &arr[mid]);
    }
    if (strcmp(arr[0], arr[last]) > 0) {
        swap(&arr[0], &arr[last]);
    }
    if (strcmp(arr[mid], arr[last]) > 0) {
        swap(&arr[mid], &arr[last]);
    }
    swap(&arr[mid], &arr[last - 1]); // Place pivot at last-1

    // Partition
    for (size_t i = 0; i < last; i++) {
        if (strcmp(arr[i], arr[last]) < 0) {
            swap(&arr[i], &arr[piv++]);
        }
    }

    swap(&arr[piv], &arr[last]);

    // Recursive calls with tail-call optimization
    quick_sort(arr, piv);
    quick_sort(arr + piv + 1, length - piv - 1);
}

#endif // !SORT