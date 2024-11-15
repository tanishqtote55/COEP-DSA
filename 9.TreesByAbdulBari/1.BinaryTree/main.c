#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

int main(){
    Treecreate();
    printf("Count : %d\n", count(root));
    printf("Count of Leaf Nodes : %d\n", countLeafNodes(root));
    printf("Count of Degree 2 Nodes : %d\n", countDegree2Nodes(root));
    printf("Count of Degree 1 Nodes : %d\n", countDegree1Nodes(root));
    printf("Count of Degree 1 and 2 Nodes : %d\n", countDegree1And2Nodes(root));
    printf("Height : %d", height(root));

    // printf("\nLevel Order ");
    // LevelOrder(root);

    // printf("\nPre Order ");
    // IPreorder(root);
    // printf("\nIn Order ");
    // IInorder(root);


    // printf("\nPre Order ");
    // Preorder(root);
    // printf("\nPost Order ");
    // Postorder(root);
    return 0;
}