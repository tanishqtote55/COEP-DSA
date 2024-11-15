#include <stdlib.h>
#include "header.h"


void init_DLL(DLL *l){
    l -> front = NULL;
    l -> rear = NULL;
}
int len(DLL *l){
    int count = 0;
    node *temp = l -> front;
    while(temp){
        count++;
        temp = temp -> next;
    }
    return count;
}
int isEmpty(DLL *l){
    if(l -> front == NULL){
        return 1;
    }
    return 0;
}
void insert_beg(DLL *l, int d){
    node *newnode = (node *)malloc(sizeof(node));
    newnode -> next = NULL;
    newnode -> prev = NULL;
    newnode -> data = d;
    if(!isEmpty(l)){
        node *temp = l -> front;
        temp -> prev = newnode;
        newnode -> next = temp;
        l -> front = newnode;
    }
    else{
        l -> front = newnode;
        l -> rear = newnode;
    }
}
void insert_end(DLL *l, int d){
    node *newnode = (node *)malloc(sizeof(node));
    newnode -> next = NULL;
    newnode -> prev = NULL;
    newnode -> data = d;
    if(!isEmpty(l)){
        node *temp = l -> front;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
        l -> rear = newnode;
    }
    else{
        l -> front = newnode;
        l -> rear = newnode;
    }
}
void insert_pos(DLL *l, int d, int index){
    node *newnode = (node *)malloc(sizeof(node));
    newnode -> next = NULL;
    newnode -> prev = NULL;
    newnode -> data = d;
    if(index == 0){
        insert_beg(l, d);
        return;
    } 
    else{
        node *temp = l -> front;
        for(int i = 0; i < index-1 && temp != NULL; i++){
            temp = temp -> next;
        }
        if(temp == NULL || temp -> next == NULL){
            insert_end(l, d);
            return;
        }
        else{
            newnode -> prev = temp;
            newnode -> next = temp -> next;
            temp -> next = newnode;
            newnode -> next -> prev = newnode;
        }
        return;
    }
}
void remove_beg(DLL *l){
    node *temp;
    if(isEmpty(l)){
        printf("List is already empty\n");
        return;
    }
    else if(l -> front  == l -> rear){
        free(l -> front);
        l -> front = NULL;
        l -> rear = NULL;
        return;
    }
    else{
        temp = l -> front;
        l -> front = l -> front -> next;
        l -> front -> prev = NULL;
        free(temp);
    }
}
void remove_end(DLL *l){
    node *temp;
    if(isEmpty(l)){
        printf("List is already empty\n");
        return;
    }
    else if(l -> front  == l -> rear){
        free(l -> front);
        l -> front = NULL;
        l -> rear = NULL;
        return;
    }
    else{
        temp = l -> rear;
        l -> rear = l -> rear -> prev;
        l -> rear -> next = NULL;
        free(temp);
    }
}
void remove_pos(DLL *l, int index){
    node *temp = l -> front;;
    if(isEmpty(l)){
        printf("List is already empty\n");
        return;
    }
    int length = len(l);
    if(index < 0 || index >= length){
        printf("Invalid index\n");
        return;
    }
    if(index == 0){
        remove_beg(l);
        return;
    }
    for(int i = 0; i < index; i++){
        temp = temp -> next;
    }
    if(temp == l -> rear){
        remove_end(l);
    }
    else{
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free(temp);
    }
}
void sort(DLL *l){
    if(isEmpty(l)){
        return;
    }
    int swap;
    node *temp;
    do{
        swap = 0;
        temp = l -> front;
        while(temp -> next != NULL){
            if(temp -> data > temp -> next -> data){
                int t = temp -> data;
                temp -> data = temp -> next -> data;
                temp -> next -> data = t;
                swap = 1;
            }
            temp = temp -> next;
        }
        l -> rear = temp;
    }while(swap);
}
void displayLR(DLL l){
    node *p;
    printf("FWD: [");
    p = l.front;
    if(!p){
        printf("]\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
}
void displayRL(DLL l){
    node *p;
    printf("BWD: [");
    p = l.rear;
    if(!p){
        printf("]\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("]\n");
}
void is_palindrome(DLL *l){
    int length = len(l);
    if(isEmpty(l)){
        printf("List is already Empty\n");
        return;
    }
    else if(length == 1){
        printf("List is a palindrome\n");
        return;
    }
    node *p = l -> front;
    node *q = l -> rear;
    while(p != q && p -> next != q){
        if(p -> data != q -> data){
            printf("List is not a palindrome\n");
            return;
        }
        p = p -> next;
        q = q -> prev;
    }
    printf("List is a palindrome\n");
    return;
}
void remove_duplicates(DLL *l){
    node *p = l -> front;
    while(p != NULL){
        node *q = p -> next;
        while(q != NULL){
            if(p -> data == q -> data){
                node *temp = q;
                q = q -> next;
                if(temp == l -> rear){
                    remove_end(l);
                }
                else{
                    temp -> prev -> next = temp -> next;
                    if(temp -> next != NULL){
                        temp -> next -> prev = temp -> prev;
                    }
                    free(temp);
                }
            }
            else{
                q = q -> next;
            }
        }
        p = p -> next;
    }
}