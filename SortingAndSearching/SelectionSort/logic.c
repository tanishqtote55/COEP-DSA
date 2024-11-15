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

void selection_sort(array *arr){
	int i, j, min_index, temp;
	for(int i = 0; i < arr -> len - 1; i++){
		min_index = i;
		for(int j = i + 1; j < arr -> len; j++){
			if(arr -> A[j] < arr -> A[min_index]){
				min_index = j;
			}
		}
		if(min_index != i){
			temp = arr -> A[i];
			arr -> A[i] = arr -> A[min_index];
			arr -> A[min_index] = temp; 
		}
	}
}

void print_array(array *arr) {
    for (int i = 0; i < arr->len; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}