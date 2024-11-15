#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(Stack *s){
    s -> top = -1;
    return;
}

int isFull(Stack *s){
    return s -> top == 99;
}

int isEmpty(Stack *s){
    return s -> top == -1;
}

void push(Stack *s, int x){
    if(!isFull(s)){
        s -> top++;
        s -> arr[s -> top] = x;
    }else{
        printf("Stack is full\n");
    }
}

int pop(Stack *s){
    if(!isEmpty(s)){
        return s -> arr[s -> top--];
    }else{
        printf("Stack is empty\n");
        return -1;
    }
}

void decimalToBinary(int number){
    Stack binary;
    init(&binary);

    while(number > 0){
        push(&binary, number % 2);
        number /= 2;
    }

    printf("Binary Number is: ");
    while(!isEmpty(&binary)){
        printf("%d", pop(&binary));
    }
    printf("\n");
}