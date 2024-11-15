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

int linearSearch(array *a, int key) {
    int i;
    for (i = 0; i < a -> len; i++) {
        if (key == a -> A[i]) {
            return i;
        }
    }
    return -1;
}

void print_array(array *arr) {
    for (int i = 0; i < arr->len; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}