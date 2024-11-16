#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    printf("Number of arguments (argc): %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    const char *filename = argv[1];
    Heap heap;
    initHeap(&heap); 

    readFromFile(filename, &heap); 
    heapSort(&heap, filename); 
    freeHeap(&heap); 
    return 0;
}
