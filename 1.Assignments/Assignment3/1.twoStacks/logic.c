#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(twoStacks *ts, int size){
    ts ->  size = size;
    ts -> arr = (int *)malloc(sizeof(int) * size);
    ts -> top1 = -1;
    ts -> top2 = size;
    return;
}

void push1(twoStacks *ts, int x){
    if(ts -> top1 < ts -> top2 - 1){
        ts -> top1++;
        ts -> arr[ts -> top1] = x;
    }else{
        printf("Stack Overflow\n");
    }
    return;
}
void push2(twoStacks *ts, int x){
    if(ts -> top1 < ts -> top2 - 1){
        ts -> top2--;
        ts -> arr[ts -> top2] = x;
    }else{
        printf("Stack Overflow\n");
    }
    return;
}

int pop1(twoStacks *ts){
    if(ts -> top1 >= 0){
        int x = ts -> arr[ts -> top1];
        ts -> top1--;
        return x;
    }else{
        printf("Stack Underflow\n");
        return -1;
    }
}
int pop2(twoStacks *ts){
    if(ts -> top2 < ts -> size){
        int x = ts -> arr[ts -> top2];
        ts -> top2++;
        return x;
    }else{
        printf("Stack Underflow\n");
        return -1;
    }
}

void display1(twoStacks *ts){
    if (ts->top1 == -1) {
        printf("Stack 1 is empty\n");
    }else{
        printf("Elements in Stack 1 are: ");
         for (int i = 0; i <= ts->top1; i++) {
            printf("%d ", ts->arr[i]);
        }
        printf("\n");
    }
}

void display2(twoStacks* ts) {
    if (ts->top2 == ts->size) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Elements in Stack 2 are: ");
        for (int i = ts -> size - 1; i >= ts -> top2 ; i--) {
            printf("%d ", ts->arr[i]);
        }
        printf("\n");
    }
}

