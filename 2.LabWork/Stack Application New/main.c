#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "header.h"
#include <string.h>

int main(){
    char infix[100], postfix[100], prefix[100];
    printf("Enter a valid infix expression: ");
    scanf("%[^\n]s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    
    // Resetting input string for infix to prefix conversion
    // strcpy(prefix, infix); // Storing the original infix expression before conversion
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    printf("Evaluated result: %d\n", result);
    return 0;
}