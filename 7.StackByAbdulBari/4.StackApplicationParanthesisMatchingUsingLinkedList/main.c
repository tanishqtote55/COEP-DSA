#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    char *exp = "((a + b) *{[]} (c - d))";
    printf("%d ", isBalanced(exp));
    return 0;
}