#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>

int main() {
    srand(time(0));
    SLL L1; 
    init_SLL(&L1);
    append(&L1);             
    append(&L1);             
    append(&L1);             
    traverse(L1);
    insert_beg(&L1);
    printf("After inserting element at beginning: ");
    traverse(L1);
    remove_pos(&L1, 2);
    printf("After removing element from position 2: ");
    traverse(L1);
    len(L1);    

   return 0;

}