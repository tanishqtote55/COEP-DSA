#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init_Stack(Stack *st, int size){
    st -> size = size;
    st -> top = -1;
    st -> A = (int *)malloc(sizeof(int) * size);
}

void push(Stack *st, int data){
    if(st -> top == st -> size - 1){
        printf("Stack Overflow\n");
    }else{
        st -> top++;
        st -> A[st -> top] = data;
    }
}

int pop(Stack *st){
    if(st -> top == -1){
        printf("Stack Underflow\n");
        return -1;
    }else{
        int x = -1;
        x = st -> A[st -> top];
        st -> top--;
        return x;
    }
}

// Index = Top - Pos + 1
int peek(Stack st, int pos){
    if(st.top - pos + 1 < 0){
        printf("Invalid Position\n");
        return -1;
    }else{
        int x = st.A[st.top - pos + 1];
        return x;
    }
}

int stackTop(Stack st){
    if(st.top == -1){
        return -1;
    }else{
        return st.A[st.top];
    }
}

int isEmpty(Stack st){
    if(st.top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack st){
    if(st.top == st.size - 1){
        return 1;
    }else{
        return 0;
    }
}

void display(Stack st){
    for(int i = st.top; i >= 0; i--){
        printf("%d ", st.A[i]);
    }
    printf("\n");
}
