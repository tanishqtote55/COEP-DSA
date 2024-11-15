#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init_Stack(Stack* st){
    st -> top = NULL;
}

void push(Stack* st, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Stack Overflow\n");
    }else{
        newNode -> data = data;
        newNode -> next = st->top;
        st->top = newNode;
    }
}

int pop(Stack* st){
    if(st -> top == NULL){
        printf("Stack Underflow\n");
        return -1;
    }else{
        Node* temp = st->top;
        int poppedData = temp->data;
        st->top = st->top->next;
        free(temp);
        return poppedData;
    }
}
int peek(Stack st, int pos){
    int i;
    Node *temp = st.top;
    for(i = 0; temp != NULL && i < pos- 1; i++){
        temp = temp -> next;
    }
    if(temp != NULL){
        return temp -> data;
    }else{
        return -1;
    }
}

int stackTop(Stack st){
    if (st.top) {
        return st.top -> data;
    } else {
        return -1;
    }
}

int isEmpty(Stack st){
    return st.top ? 0 : 1;
}

int isFull(){
    Node *temp = (Node*)malloc(sizeof(Node));
    int r = temp ? 0 : 1;
    free(temp);
    return r;
}


void display(Stack st){
    Node* temp = st.top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}