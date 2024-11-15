#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init(Array *a, int size){
    a->data = (int *)malloc(size * sizeof(int));
    a->len = 0;
    a->size = size;
    return;

}

void append(Array *a, int value){
    if(a->len > a->size-1) return;
        a->data[a->len] = value;
        a->len++;
    return;

}

void display(Array * a){
    for(int i = 0 ;i<a->len;i++){
        printf("%d ", a->data[i]);
    }
    printf("\n");
    return;

}

void insert_at_index(Array *a, int ind, int value) {
    // Check if the index is valid and there's space for the new element
    if (ind < 0 || ind > a->len || a->len >= a->size) {
        return;  // Invalid index or no space available
    }

    // Shift elements to the right to make space for the new element
    for (int i = a->len; i > ind; i--) {
        a->data[i] = a->data[i - 1];
    }

    // Insert the new element at the specified index
    a->data[ind] = value;
    a->len++;
}

void remove_at_index(Array *a, int ind) {
    // Check if the index is valid
    if (ind < 0 || ind >= a->len) {
        return;  // Invalid index
    }

    // Shift elements to the left to fill the gap created by removal
    for (int i = ind; i < a->len - 1; i++) {
        a->data[i] = a->data[i + 1];
    }

    // Decrease the length of the array
    a->len--;
}

int maxele(Array * arr){
    int max = arr->data[0];
    for(int i = 1; i < arr -> len; i++){
        if(arr -> data[i] > max){
            max = arr -> data[i];
        }
    }
    return max;
}


int minele(Array * arr){
        int min = arr->data[0];
    for(int i = 1;i<arr->size;i++){
        if(arr->data[i] < min){
            min = arr->data[i];
        }
    }
    return min;
}

void reverse(Array * arr){
    int l = 0, h= arr->len-1;

    while(l<h){
        int temp = arr->data[l];
        arr->data[l] = arr->data[h];
        arr->data[h] = temp;
        l++;
        h--;
    }
}

void merge(Array *a, Array *b) {
    // Ensure enough space in array a to merge b
    if (a->len + b->len > a->size) {
        // Resize array a to accommodate all elements of both arrays
        a->size = a->len + b->len;
        a->data = (int *)realloc(a->data, a->size * sizeof(int));
    }

    // Append each element of array 'b' to array 'a'
    for (int i = 0; i < b->len; i++) {
        append(a, b->data[i]);  // Assumes append will handle resizing if needed
    }

    display(a);  // Show the merged array
}
void mov_neg(Array * a){
    Array * c, *b;
    init(c,20);
    init(b,20);

    for(int i = 0;i<a->len;i++){
        if(a->data[i] < 0){
            append(c,a->data[i]);
        }
        else{
            append(b,a->data[i]);
        }
    }
    int i = 0, j = 0;
    while(i<c->len){
        a->data[i]  = c->data[i]; 
        i++;
    }
    while(j<b->len){
        a->data[i] = c->data[j];
        j++;
        i++;
    }

}