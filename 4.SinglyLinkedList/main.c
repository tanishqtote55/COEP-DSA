#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    SLL L1;
    init_SLL(&L1);
    insert_beg(&L1, 5);
    insert_end(&L1, 20);
    insert_pos(&L1, 10, 2);
    display(&L1);
    remove_pos(&L1, 3);
    display(&L1);
    remove_end(&L1);
    display(&L1);
    remove_beg(&L1);
    display(&L1);
    return 0;
}