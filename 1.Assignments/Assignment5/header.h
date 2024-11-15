#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char month[10];
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

typedef struct {
    Node* root;
} BST;

void initBST(BST* tree);
Node* createNode(char* month);
void insertNode(BST* tree, char* month);
Node* searchNode(BST* tree, char* month);
void removeNode(BST* tree, char* month);
void traverse(Node* node);
void destroyTree(Node* node);