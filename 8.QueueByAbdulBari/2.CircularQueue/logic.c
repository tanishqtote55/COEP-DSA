#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(Queue *q, int size){
    q -> size = size;
    q -> front = 0;
    q -> rear = 0;
    q -> Q = (int *)malloc(sizeof(int) * size);
}

void enqueue(Queue *q, int data){
    if((q -> rear + 1) % (q -> size) == q -> front){
        printf("Queue is full\n");
    }else{
        q -> rear = (q -> rear + 1) % (q -> size);
        q -> Q[q -> rear] = data;
    }
}

int dequeue(Queue *q){
    if(q -> front == q -> rear){
        printf("Queue is Empty\n");
        return -1;
    }else{
        int x;
        q -> front = (q -> front + 1) % (q -> size);
        x = q -> Q[q -> front];
        return x;
    }
}

void Display(Queue q){
    int i = q.front + 1;
    do{
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    }while(i != (q.rear + 1) % (q.size));
    printf("\n");
}