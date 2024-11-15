#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#include <time.h>

#define min 1
#define max 100

void init_SLL(SLL *head){
    *head = NULL;
    return;
}

void append(SLL *head){
    int randomNumber;
    int minimum = 1;
    int maximum = 100;
    
    randomNumber = (rand() % (maximum - minimum + 1)) + minimum;
    node *p, *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = randomNumber;
        newnode->next = NULL;
    }
    else return;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    p = *head;
    while(p -> next) {
       p = p->next;
    }
    p->next = newnode;
    return;
}

void traverse(SLL head){
    printf("[");
    node *p;
    p = head;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}

void insert_beg(SLL *head){
    int randomNumber;
    randomNumber = (rand() % (max - min + 1)) + min;
    node  *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = randomNumber;
        newnode->next = NULL;
    }
    else return;
    newnode->next = *head;
    *head = newnode;
    return;
}

void remove_pos(SLL *head, int pos){
    int i = 1;
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node *temp = *head, *prev = NULL;
    if (pos == 1) {
        *head = temp->next;  
        free(temp);  
        return;
    }
    while (temp != NULL && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp); 
}

void len(SLL head) {
    int length = 0;
    node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    printf("The length of the list is: %d\n", length);
}
