#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    int number;
    printf("Enter the Decimal Number: ");
    scanf("%d", &number);
    decimalToBinary(number);
    return 0;
}