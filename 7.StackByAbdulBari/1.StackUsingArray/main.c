#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    Stack st;
    int size;
    printf("Enter the size of Stack: ");
    scanf("%d", &size);
    init_Stack(&st, size);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    printf("%d \n", isFull(st));

    printf("%d \n", peek(st, 2));
    printf("%d \n", stackTop(st));
    display(st);

    printf("%d \n", pop(&st));

    printf("%d \n", pop(&st));
    printf("%d \n", pop(&st));
    printf("%d \n", pop(&st));
    printf("%d \n", pop(&st));

    printf("%d \n", isEmpty(st));
    return 0;
}