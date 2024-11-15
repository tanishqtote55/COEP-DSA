#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(Queue *q){
    q -> front = NULL;
    q -> rear = NULL;
}

void enqueue(Queue *q, int data){
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode == NULL){
        printf("Queue is Full\n");
    }else{
        newnode -> data = data;
        newnode -> next = NULL;
        if(q -> front == NULL){
            q -> front = q -> rear = newnode;
        }else{
            q -> rear -> next = newnode;
            q -> rear = newnode;
        }
    }
}

int dequeue(Queue *q){
    Node *temp;
    if(q -> front == NULL){
        printf("Queue is empty\n");
        return -1;
    }else{
        int x = q -> front -> data;
        temp = q -> front;
        q -> front = q -> front -> next;
        free(temp);
        return x;
    }
}

void Display(Queue q){
    Node *temp = q.front;
    while(temp){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

