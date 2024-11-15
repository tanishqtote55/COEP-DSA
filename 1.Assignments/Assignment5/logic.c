#include "header.h"

void initBST(BST* tree){
    tree->root = NULL;
}

Node* createNode(char* month){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->month, month);
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void insertNode(BST* tree, char* month) {
    Node* newNode = createNode(month);
    Node* current = tree->root;
    Node* parent = NULL;

    // Traverse the tree to find the correct parent for the new node
    while (current != NULL) {
        parent = current;
        
        // Compare alphabetically and move left or right
        if (strcmp(month, current->month) < 0)
            current = current->left;
        else
            current = current->right;
    }

    // Attach the new node to the appropriate parent
    newNode->parent = parent;
    if (parent == NULL) {
        // Tree was empty; new node is the root
        tree->root = newNode;
    } else if (strcmp(month, parent->month) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}


Node* searchNode(BST* tree, char* month){
    Node* current = tree->root;
    while (current != NULL && strcmp(month, current->month) != 0) {
        if (strcmp(month, current->month) < 0)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

void removeNode(BST* tree, char* month){
    Node* node = searchNode(tree, month);
    if (node == NULL) {
        printf("Node with month %s not found.\n", month);
        return;
    }

    Node* y;
    Node* x;

    if (node->left == NULL || node->right == NULL)
        y = node;
    else {
        y = node->right;
        while (y->left != NULL)
            y = y->left;
    }

    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;

    if (x != NULL)
        x->parent = y->parent;

    if (y->parent == NULL)
        tree->root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if (y != node)
        strcpy(node->month, y->month);

    free(y);
}

void traverse(Node* node){
    if (node == NULL)
        return;

    Node* current = node;
    Node* pre;

    while (current != NULL) {
        if (current->left == NULL) {
            printf("%s ", current->month);
            current = current->right;
        } else {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                printf("%s ", current->month);
                current = current->right;
            }
        }
    }
    printf("\n");
}

void destroyTree(Node* node){
    if (node == NULL)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    free(node);
}
