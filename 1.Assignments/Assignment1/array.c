#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void init(array *a, int size){
    a -> A = (int *)malloc(sizeof(int) * size);
    a -> size = size;
    a -> length = 0;
    return;
}

void append(array *a, int element){
    if(a -> length < a -> size){
        a -> A[a -> length++] = element;
    }
    return;
}

void insert_at_index(array *a, int position, int element){
    if(position >= 0 && position <= (a -> length) && a -> length < a -> size){
        for(int i = a -> length; i > position; i--){
            a -> A[i] = a -> A[i - 1];
        }
        a -> A[position] = element;
        a -> length++;
    }
    else if(a -> length == a -> size){
        printf("Array is full\n");
    }
    else{
        printf("Invalid Position\n");
    }
}

void remove_at_index(array *a, int position){
    if(position >= 0 && position < a -> length){
        for(int i = position; i < a -> length - 1; i++){
            a -> A[i] = a -> A[i + 1];
        }
        a -> length--;
    }
    else{
        printf("Invalid Position\n");
    }
}

void display(array *a){
    for(int i = 0; i < a -> length; i++){
        printf("%d |", a -> A[i]);
    }
    return;
}

int max(array a){
    int max = INT_MIN;
    for(int i = 0; i < a.length; i++){
        if(a.A[i] > max){
            max = a.A[i];
        }
    }
    return max;
}

int min(array a){
    int min = INT_MAX;
    for(int i = 0; i < a.length; i++){
        if(a.A[i] < min){
            min = a.A[i];
        }
    }
    return min;
}

void reverse(array *a){
    for(int i = 0; i < a -> length / 2 ; i++){
        int temp = a -> A[i];
        a -> A[i] = a -> A[a -> length - 1 - i];
        a -> A[a -> length - 1 - i] = temp;
    }
}

array *merge(array *a, array *b){
    array *c = (array*)malloc(sizeof(array));
    init(c, a -> length + b -> length);
    for(int i = 0; i < a -> length; i++){
        c -> A[i] = a -> A[i];
    }
    for(int i = 0; i < b -> length; i++){
        c -> A[a -> length + i] = b -> A[i];
    }
    c -> length = a -> length + b -> length;
    return c;
}