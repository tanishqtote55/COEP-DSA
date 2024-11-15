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

void bubble_sort(array *arr){
	int temp;
	for(int i = 0; i < arr->len - 1; i++){
		for(int j = 0; j < arr->len - 1 - i; j++){
			if(arr -> A[j] > arr -> A[j+1]){
				temp = arr -> A[j];
				arr -> A[j] = arr -> A[j + 1];
				arr -> A[j + 1] = temp;
			}
		}
	}
}

int binarySearch(array a, int key) {
    int l, h, mid;
    l = 0;
    h = a.len - 1;

    while (l <= h) {
        mid = (l + h) / 2;
        if (key == a.A[mid])
            return mid;
        else if (key < a.A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
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