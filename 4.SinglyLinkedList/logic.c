#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init_SLL(SLL *head){
    *head = NULL;
    return;
}

void insert_beg(SLL *head, int d){
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode -> data = d;
        newnode -> next = NULL;
    }else return;
    newnode -> next = *head;
    *head = newnode;
    return;
}

void insert_end(SLL *head, int d){
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode -> data = d;
        newnode -> next = NULL;
    }else return;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    node *temp = *head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newnode;
    return;
}

void insert_pos(SLL *head, int d, int pos){
    // printf("%d\n", length(head));
    if(pos > length(head) + 1 || pos < 0){
        printf("Invalid position\n");
        return;
    }else{
        int i = 1;
        node *temp = *head;
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode){
            newnode -> data = d;
            newnode -> next = NULL;
        }else return;
        if (pos == 1) {
            newnode->next = *head;
            *head = newnode;
            return;
        }
        while(i < pos - 1){
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

int length(SLL *head){
    int count = 0;
    node *temp = *head;
    while(temp){
        count++;
        temp = temp -> next;
    }
    return count;
}

void remove_beg(SLL *head){
    if(*head == NULL){
        printf("Linked List is Empty\n");
        return;
    }else{
        node *temp = *head;
        *head = temp -> next;
        free(temp);
        return;
    }
}

void remove_end(SLL *head){
    if(*head == NULL){
        printf("Linked List is Empty\n");
        return;
    }else{
        node *temp = *head;
        node *prevnode;
        while(temp -> next){
            prevnode = temp;
            temp = temp -> next;
        }
        if(temp == *head){
            head = 0;
            free(temp);
        }else{
            prevnode -> next = NULL;
            free(temp);
        }
    }
}

void remove_pos(SLL *head, int pos){
    if(pos > length(head) || pos < 0){
        printf("Invalid position\n");
        return;
    }else{
        node *temp, *nextnode;
        if(pos == 1){
            remove_beg(head);
            return;
        }else{
            int i = 1;
            temp = *head;
            while(i < pos - 1){
                temp = temp -> next;
                i++;
            }
            nextnode = temp -> next;
            temp -> next = nextnode -> next;
            free(nextnode);
            return;
        }
    }
}

void display(SLL *head){
    if(*head == NULL){
        printf("Linked List is Empty");
        return;
    }else{
        node *temp = *head;
        while(temp){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
        return;
    }  
}