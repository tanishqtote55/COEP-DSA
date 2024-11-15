#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void init(Stack *s, int size) {
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char) * size);
}
int isFull(Stack *s){
    return s -> top == 99;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
    }
    return s -> arr[s->top--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return 0;
    }
    return s->arr[s->top];
}

void reverseString(char exp[]){
    int len = strlen(exp);
    Stack s;
    init(&s, len);
    int i;
    for(i = 0; i < len; i++){
        push(&s, exp[i]);
    }
    for(i = 0; i < len; i++){
        exp[i] = pop(&s);
    }
}