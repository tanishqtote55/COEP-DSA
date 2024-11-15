#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    Stack st;
    init_Stack(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    printf("Is stack full? %d\n", isFull());

    printf("Top element is %d\n", stackTop(st));
    printf("2nd element is %d\n", peek(st, 2));
    printf("Stack elements:\n");
    display(st);

    printf("Popped element: %d\n", pop(&st));
    printf("Popped element: %d\n", pop(&st));

    printf("Is stack empty? %d\n", isEmpty(st));

    printf("Stack elements after popping:\n");
    display(st);
    return 0;
}