#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Initialize the queue
void qinit(queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int qempty(queue *q) {
    return (q->front == NULL);
}

int isqfull() {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        return 1; // Queue is full (memory allocation failed)
    }
    free(temp); // Free the memory if allocation was successful
    return 0;   // Queue is not full
}

// Add an element to the queue
void enqueue(queue *q, int value) {
    if (isqfull()) {
        printf("Memory allocation failed, cannot enqueue data.\n");
        return;
    }

    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed, cannot enqueue data.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) { // Queue is empty
        q->front = newNode;
        q->rear = newNode;
    } else { // Add the new node to the end of the queue
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Remove and return the front element from the queue
int dequeue(queue *q) {
    if (qempty(q)) {
        printf("Queue is empty, cannot dequeue data.\n");
        return -1; // Indicate an error
    }

    int value = q->front->data;
    node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) { // If the queue is now empty
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Peek at the front element without removing it
int peek(queue *q) {
    if (qempty(q)) {
        printf("Queue is empty, nothing to peek.\n");
        return -1; // Indicate an error
    }
    return q->front->data;
}

// Display the elements of the queue
void display(queue *q) {
    if (qempty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    node *current = q->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
