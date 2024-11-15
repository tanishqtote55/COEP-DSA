#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

void init(array *arr, int size){
	arr -> A = (int *)malloc(sizeof(int) * size);
	arr -> size = size;
	arr -> len = 0;
}

void append(array *arr, int d){
	if(arr -> len < arr -> size){
		arr -> A[arr -> len++] = d;
	}
}

void insertion_sort(array *arr) {
    int i, j, key;
    for (i = 1; i < arr->len; i++) {  
        key = arr->A[i];  
        j = i - 1;

        while (j >= 0 && arr->A[j] > key) {
            arr->A[j + 1] = arr->A[j];
            j = j - 1;
        }
        arr->A[j + 1] = key;  
    }
}

void print_array(array *arr) {
    for (int i = 0; i < arr->len; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}