#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int size;
    int *a;
}stack;

void init(stack *s, int size);
int isFull(stack s);
int isEmpty(stack s);
void push(stack *s, int data);
int pop(stack *s);
int stackTop(stack s);
void display(stack s);
void peek(stack *s, int index);