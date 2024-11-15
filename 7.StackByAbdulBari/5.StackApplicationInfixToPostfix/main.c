#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "header.h"

int main(){
    char infix[100], postfix[100];
    printf("Enter a valid infix expression: ");
    scanf("%[^\n]s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated result: %d\n", result);
    return 0;
}