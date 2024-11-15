#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    Display(q);

    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));

    Display(q);
    return 0;
}