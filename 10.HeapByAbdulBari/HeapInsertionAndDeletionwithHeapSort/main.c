#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};

    for(int i=2;i<=7;i++)
        Insert(H,i);

    for(int i = 1; i <= 7; i++)
        printf("%d ", H[i]); 
    printf("\n"); 

    for(int i=7;i>1;i--){
        Delete(H,i);
    }

    for(int i = 1; i <= 7; i++)
        printf("%d ", H[i]); 
    printf("\n"); 

    return 0;
}