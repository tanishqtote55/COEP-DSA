#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

int main(){
    // Doesn't Works for Operators having right to left associativity
    char *infix = "a+b*c-d/e";
    char *postfix = infixToPostfix(infix);  
    printf("%s", postfix);
    return 0;
}