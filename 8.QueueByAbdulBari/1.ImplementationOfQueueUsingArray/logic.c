#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(Queue *q, int size){
    q -> size = size;
    q -> front = -1;
    q -> rear = -1;
    q -> Q = (int *)malloc(sizeof(int) * size);
}

void enqueue(Queue *q, int data){
    if(q -> rear == q -> size - 1){
        printf("Queue is full\n");
    }else{
        q -> rear++;
        q -> Q[q -> rear] = data;
    }
}

int dequeue(Queue *q){
    if(q -> front == q -> rear){
        printf("Queue is Empty\n");
        return -1;
    }else{
        int x;
        q -> front++;
        x = q -> Q[q -> front];
        return x;
    }
}

void Display(Queue q){
    for(int i = q.front + 1; i <= q.rear; i++){
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}