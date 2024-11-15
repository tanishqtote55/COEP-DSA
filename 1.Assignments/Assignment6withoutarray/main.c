// main.c
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    Heap heap;
    initHeap(&heap);

    readFromFile(filename, &heap);
    heapSort(&heap, filename);

    return 0;
}

