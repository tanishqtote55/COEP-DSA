#include "header.h"
int main(){
    DLL L1;
    init_DLL(&L1);
    insert_beg(&L1, 5);
    insert_end(&L1, 10);
    insert_pos(&L1, 15, 2);
    insert_pos(&L1, 20, 3);
    insert_end(&L1, 15);
    insert_end(&L1, 10);
    insert_end(&L1, 5);
    displayLR(L1);
    displayRL(L1);
    is_palindrome(&L1);
    sort(&L1);
    printf("After Sorting: ");
    displayLR(L1);
    remove_duplicates(&L1);
    printf("After removing duplicates: ");
    displayLR(L1);
    remove_beg(&L1);
    printf("After removing element from beginning: ");
    displayLR(L1);
    remove_end(&L1);
    printf("After removing element from end: ");
    displayLR(L1);
    remove_pos(&L1, 1);
    printf("After removing element from index 1: ");
    displayLR(L1);
    return 0;
}