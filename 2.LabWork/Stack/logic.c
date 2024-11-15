#include "header.h"

void init(stack *s, int size){
    s -> size = size;
    s -> top = -1;
    s -> a = (int *)malloc(sizeof(int)*size);
}
int isFull(stack s){
    if(s.top == s.size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(stack s){
    if(s.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(stack *s, int data){
    if(isFull(*s)){
        printf("Stack is Full\n");
        return;
    }
    s -> top++;
    s -> a[s -> top] = data;
}
int pop(stack *s){
    if(isEmpty(*s)){
        printf("Stack is Empty\n");
        return -1;
    }
    else{
        int popped = s -> a[s -> top];
        s -> top--;
        return popped;
    }
}
int stackTop(stack s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }
    return s.a[s.top];
}
void display(stack s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        int i;
        for(i = s.top; i >= 0; i--){
            printf("%d ", s.a[i]);
        }
        printf("\n");
    }
}
void peek(stack *s, int index){
    if(index <= 0 || index > s -> top + 1){
        printf("Invalid Index\n");
    }
    else{
        int x = s -> a[s -> top - index + 1];
        printf("Element at index %d from the top: %d\n", index, x);
    }
}