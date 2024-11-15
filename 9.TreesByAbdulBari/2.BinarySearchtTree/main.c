#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    Node *temp;

    // Insert(10);
    // Insert(5);
    // Insert(20);
    // Insert(8);
    // Insert(30);

    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 40);
    RInsert(root, 20);
    RInsert(root, 30);

    Inorder(root);
    printf("\n");

    temp = Search(20);
    if(temp != NULL){
        printf("element %d is found\n", temp -> data);
    }else{
        printf("element is not found\n");
    }

    Delete(root, 50);

    Inorder(root);
    return 0;
}