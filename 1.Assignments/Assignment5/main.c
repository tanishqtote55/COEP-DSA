#include "header.h"

int main() {
    BST tree;
    initBST(&tree);
    
    int choice;
    char month[10];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Remove a node\n");
        printf("3. Traverse the tree\n");
        printf("4. Destroy the tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter month to insert: ");
                scanf("%s", month);
                insertNode(&tree, month);
                break;
            case 2:
                printf("Enter month to remove: ");
                scanf("%s", month);
                removeNode(&tree, month);
                break;
            case 3:
                printf("In-order traversal of the tree:\n");
                traverse(tree.root);
                break;
            case 4:
                destroyTree(tree.root);
                tree.root = NULL;
                printf("Tree destroyed.\n");
                break;
            case 5:
                destroyTree(tree.root);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}