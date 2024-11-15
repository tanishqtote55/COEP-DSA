#include "header.h"

int main(){
    CLL L1;
    init_CLL(&L1);
    insert_beg(&L1, 5);
    insert_beg(&L1, 10);
    insert_beg(&L1, 15);
    insert_end(&L1, 20);
    insert_end(&L1, 25);
    insert_end(&L1, 30);
    display(&L1);
    insert_pos(&L1, 50, 4);
    display(&L1);
    sort(&L1);
    printf("After Sorting: ");
    display(&L1);
    remove_beg(&L1);
    printf("After removing first element: ");
    display(&L1);
    remove_end(&L1);
    printf("After removing last element: ");
    display(&L1);
    remove_pos(&L1, 3);
    printf("After removing element from position 3: ");
    display(&L1);
    return 0;
}