#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    char exp[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", exp);
    reverseString(exp);
    printf("Reversed string: %s\n", exp);
    return 0;
}