#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if(paranthesisBalanced(exp)){
        printf("The expression is balanced.\n");
    }else{
        printf("The expression is not balanced.\n");
    }
    return 0;
}