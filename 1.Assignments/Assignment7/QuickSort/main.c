#include <stdio.h>
#include "header.h"
#include <stdlib.h>

int main() {
    array  arr;
    init(&arr, 5);
    append(&arr, 5);
    append(&arr, 8);
    append(&arr, 9);
    append(&arr, 3);
    append(&arr, 2);

    printf("Original array: ");
    printArray(&arr);

    quickSort(&arr, 0, arr.len - 1);

    printf("Sorted array: ");
    printArray(&arr);

    return 0;
}
