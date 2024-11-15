#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

int main(){
    Queue q;
    int size;
    printf("Enter the size of Queue: ");
    scanf("%d", &size);
    init(&q, size);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    Display(q);

    dequeue(&q);
    dequeue(&q);

    Display(q);
    return 0;
}