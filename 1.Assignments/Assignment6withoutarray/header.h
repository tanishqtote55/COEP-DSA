// header.h
#ifndef HEADER_H
#define HEADER_H

// Define the max size for the heap
#define MAX_HEAP_SIZE 100

// Structure to define a Heap
typedef struct {
    int data[MAX_HEAP_SIZE];
    int size;
} Heap;

// Function prototypes
void initHeap(Heap *heap);
void insertHeap(Heap *heap, int value);
int deleteMin(Heap *heap);
void heapify(Heap *heap);
// void heapSort(Heap *heap);
void heapSort(Heap *heap, const char *filename);
void readFromFile(const char *filename, Heap *heap);

#endif
