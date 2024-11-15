// logic.c
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Initialize the heap
void initHeap(Heap *heap) {
    heap->size = 0;
}

// Insert an element into the heap
void insertHeap(Heap *heap, int value) {
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("Heap overflow: Cannot insert %d\n", value);
        return;
    }
    int i = heap->size++;
    while (i > 0 && heap->data[(i - 1) / 2] > value) {
        heap->data[i] = heap->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->data[i] = value;
}

// Delete the minimum element from the heap
int deleteMin(Heap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        return -1;
    }
    int min = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapify(heap);
    return min;
}

// Maintain the heap property
void heapify(Heap *heap) {
    int i = 0;
    while (i * 2 + 1 < heap->size) {
        int minChild = i * 2 + 1;
        if (minChild + 1 < heap->size && heap->data[minChild + 1] < heap->data[minChild]) {
            minChild++;
        }
        if (heap->data[i] <= heap->data[minChild]) {
            break;
        }
        int temp = heap->data[i];
        heap->data[i] = heap->data[minChild];
        heap->data[minChild] = temp;
        i = minChild;
    }
}

// Sort the heap and display sorted elements
// void heapSort(Heap *heap) {
//     int originalSize = heap->size;
//     printf("Sorted integers: ");
//     for (int i = 0; i < originalSize; i++) {
//         printf("%d ", deleteMin(heap));
//     }
//     printf("\n");
// }
void heapSort(Heap *heap, const char *filename) {
    int originalSize = heap->size;
    // Open the file in append mode to add sorted and unsorted contents
    FILE *file = fopen(filename, "a");
    if (!file) {
        printf("Error opening file for writing\n");
        return;
    }
    // Write sorted integers to the file
    printf("Sorted integers: ");
    fprintf(file, "\nSorted integers: ");
    for (int i = 0; i < originalSize; i++) {
        int minValue = deleteMin(heap);
        printf("%d ", minValue);
        fprintf(file, "%d ", minValue);  // Write each sorted integer to the file
    }
    fclose(file);
}


// Read integers from a file and insert them into the heap
void readFromFile(const char *filename, Heap *heap) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        exit(1);
    }
    int value;
    while (fscanf(file, "%d,", &value) != EOF) {  // Added comma to handle comma-separated format
        printf("Read value: %d\n", value); // Debugging statement
        insertHeap(heap, value);
    }
    fclose(file);
}

