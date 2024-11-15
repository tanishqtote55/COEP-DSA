#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100 

typedef struct Heap {
    int *a;    
    int size;  
    int rear;  
} Heap;

void initHeap(Heap *heap);
void freeHeap(Heap *heap);
void insert(Heap *heap, int value);
int deleteMin(Heap *heap);
void heapify(Heap *heap);
void heapSort(Heap *heap, const char *filename);
void readFromFile(const char *filename, Heap *heap);

