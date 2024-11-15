#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Function to initialize the queue
void qinit(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

// Function to check if the queue is empty
int qempty(queue *q) {
    return (q->head == NULL);
}

// Function to check if the queue is full
int qfull(queue *q) {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        return 1; // Queue is full (memory allocation failed)
    }
    free(temp);
    return 0; // Queue is not full
}

// Function to add an element to the queue
void enq(queue *q, data d) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed, cannot enqueue data.\n");
        return;
    }

    newNode->value = d;
    newNode->next = NULL;

    if (qempty(q)) {
        q->head = newNode;
        q->tail = newNode;
        newNode->next = newNode; // Circular connection to itself
    } else {
        newNode->next = q->head; // Link new node to head
        q->tail->next = newNode; // Tail's next points to new node
        q->tail = newNode;       // Update tail to new node
    }
}

// Function to remove an element from the queue
data deq(queue *q) {
    data d;
    node *temp;

    if (qempty(q)) {
        printf("Queue is empty, cannot dequeue data.\n");
        return d; // Return an empty data struct
    }

    temp = q->head;
    d = temp->value;

    if (q->head == q->tail) { // Only one node in the queue
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->tail->next = q->head; // Maintain circular connection
    }

    free(temp);
    return d;
}
