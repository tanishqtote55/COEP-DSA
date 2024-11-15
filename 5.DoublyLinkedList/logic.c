#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init_DLL(DLL *l){
    l->head = NULL;
    l->tail = NULL;
    return;
}

int isempty(DLL l) {
    return (l.head == NULL);
}

void insert_right(DLL *l, int d){
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode -> next = NULL;
        newnode -> prev = NULL;
    }else return;
    if(l -> head == NULL){
        l-> head = newnode;
        l -> tail = newnode;
        return;
    }else{
        node *temp = l -> head;
        while(temp -> next){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
        l -> tail = newnode;
        return;
    }
}
void insert_left(DLL *l, int d){
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode -> next = NULL;
        newnode -> prev = NULL;
    }else return;
    if(l -> head == NULL){
        l -> head = newnode;
        l -> tail = newnode;
        return;
    }else{
        node *temp = l -> head;
        l -> head = newnode;
        newnode -> next = temp;
        temp -> prev = newnode;
        return;
    }
}

void insert_pos(DLL *l, int d, int pos){
    if(pos > length(l) || pos < 1){
        printf("Invalid position\n");
        return;
    }else{
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode){
            newnode->data = d;
            newnode -> next = NULL;
            newnode -> prev = NULL;
        }else return;
        if(pos == 1){
            insert_left(l, d);
            return;
        }else{
            int i = 1;
            node *temp = l -> head;
            while(i < pos - 1){
                temp = temp -> next;
                i++;
            }
            newnode -> next = temp -> next;
            temp -> next -> prev = newnode;
            temp -> next = newnode;
            return;
        }
    }
}

void displayLR(DLL *l){
    node *temp = l->head;
    printf("Fwd: [ ");
    if(!temp){
        printf("]\n");
        return;
    }
    while(temp){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("]\n");
    return;
}

void displayRL(DLL *l){
    node *temp = l -> tail;
    printf("Bwd: [ ");
    if(!temp){
        printf("]\n");
        return;
    }
    while(temp){
        printf("%d ", temp -> data);
        temp = temp -> prev;
    }
    printf("]\n");
    return;
}

int length(DLL *l){
    int count = 0;
    node *temp = l -> head;
    while(temp){
        count++;
        temp = temp -> next;
    }
    return count;
}

void remove_beg(DLL *l){
    if(l -> head == NULL){
        printf("Linked List is Empty");
        return;
    }
    node *temp = l -> head;
    l -> head = temp -> next;
    if(l -> head){
        l -> head -> prev = NULL;
    }else{
        l -> tail = NULL;
    }
    free(temp);
    return;
}

void remove_end(DLL *l){
    if(l -> head == NULL){
        printf("Linked List is Empty");
        return;
    }
    node *temp = l -> tail;
    l -> tail = temp -> prev;
    if(l -> tail){
        l -> tail -> next = NULL;
    }else{
        l -> head = NULL;
    }
    free(temp);
    return;
}

void remove_pos(DLL *l, int pos){
    if(pos < 1 || pos > length(l)){
        printf("Invalid Position");
        return;
    }else{
        if(pos == 1){
            remove_beg(l);
            return;
        }else{
            int i = 1;
            node *temp = l -> head;
            while(i < pos - 1){
                temp = temp -> next;
                i++;
            }
            if(temp != NULL && temp -> next !=  NULL){
                node *nextnode = temp -> next;
                if (nextnode->next != NULL) {  
                    nextnode->next->prev = temp;
                }else{
                    l -> tail = temp;
                }
                temp -> next = nextnode -> next;
                free(nextnode);
            }else {
                printf("Position out of bounds\n");
            }
            return;
        }
    }
}

void reverse(DLL *l){

}

void SortedInsert(DLL *l, int x) {
    node *t = (node *)malloc(sizeof(node));
    node *temp;
    temp = l -> head;
    t->data = x;
    t->prev = NULL;
    t->next = NULL;

    // If the list is empty
    if (l -> head == NULL) {
        l -> head = l -> tail = t; // Both front and rear point to the new node
    }
    else {
        // Traverse to find the appropriate position
        while (temp && temp->data < x) {
            temp = temp->next;
        }

        // Inserting at the beginning of the list
        if (temp == l -> head) {
            t->next = l -> head;
            l -> head -> prev = t;
            l -> head = t;
        } 
        // Inserting at the end of the list
        else if (temp == NULL) {
            l -> tail -> next = t;
            t->prev = l -> tail;
            l -> tail = t;
        }
        // Inserting in the middle of the list
        else {
            t->prev = temp->prev;
            t->next = temp;
            temp->prev->next = t;
            temp->prev = t;
        }
    }
}


void removelist(DLL *l, int d)
{
    if (isempty(*l))
        return;
    node *p = l->head;
    while (p->data != d && p->next)
        p = p->next;
    if (p->data == d)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}

void freelist(DLL *l)
{
    node *p = l->head;
    node *q;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    l->head = NULL;
    l->tail = NULL;
}

void sort(DLL *l)
{
    node *p1 = l->head;
    node *temp = NULL;
    int x;
    if (!p1)
        return;
    node *p2 = p1->next;
    while (p2)
    {
        temp = p1;
        x = p2->data;
        while (temp && temp->data > x)
        {
            temp->next->data = temp->data;
            temp = temp->prev;
        }
        if (!temp)
            l->head->data = x;

        else
            temp->next->data = x;
        p2 = p2->next;
        p1 = p1->next;
    }
}

int search(DLL l, int d)
{
    node *p = l.head;
    while (p)
    {
        if (p->data == d)
            return 1;
        p = p->next;
    }
    return 0;
}

DLL listunion(const DLL l1, DLL l2)
{
    DLL l3;
    init_DLL(&l3);
    node *ptr1 = l1.head;
    while (ptr1)
    {
        insert_right(&l3, ptr1->data);
        ptr1 = ptr1->next;
    }

    node *ptr2 = l2.head;
    while (ptr2)
    {
        if (!search(l3, ptr2->data))
        {
            insert_right(&l3, ptr2->data);
        }
        ptr2 = ptr2->next;
    }

    return l3;
}

DLL intersection(DLL l1, DLL l2)
{
    DLL l3;
    init_DLL(&l3);
    int x;
    node *p = l1.head;
    while (p)
    {
        x = p -> data;
        if (search(l2, x))
        {
            insert_right(&l3, x);
        }
        p = p->next;
    }
    return l3;
}


void removeDuplicates(DLL *l) {
    if (isempty(*l)) return;

    node *current = l->head;
    node *temp, *duplicate;

    // Outer loop to pick each element one by one
    while (current && current->next) {
        temp = current->next;

        // Inner loop to check for duplicates
        while (temp) {
            // If a duplicate is found
            if (current->data == temp->data) {
                duplicate = temp;
                
                // Adjust the links
                if (duplicate->prev)
                    duplicate->prev->next = duplicate->next;
                if (duplicate->next)
                    duplicate->next->prev = duplicate->prev;

                // Update the rear pointer if the duplicate is the last element
                if (duplicate == l->tail)
                    l->tail = duplicate->prev;

                // Free the duplicate node
                node *nextTemp = duplicate->next;
                free(duplicate);
                temp = nextTemp;  // Move to the next node
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}
