#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    twoStacks ts;
    init(&ts, 5);
    push1(&ts, 5);
    push2(&ts, 10);
    push1(&ts, 15);
    push2(&ts, 20);
    push1(&ts, 25);
    push2(&ts, 25);
    display1(&ts);
    display2(&ts);
    printf("Popped element from stack 1: %d\n", pop1(&ts));
    printf("Popped element from stack 2: %d\n", pop2(&ts));
    display1(&ts);
    display2(&ts);
    return 0;
}