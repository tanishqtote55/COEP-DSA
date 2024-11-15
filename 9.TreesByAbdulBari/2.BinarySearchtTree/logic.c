#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Node *root = NULL;

void Insert(int key){
    Node *temp = root;
    Node *r, *p;
    if(root == NULL){
        p = (Node *)malloc(sizeof(Node));
        p -> data = key;
        p -> lchild = p -> rchild = NULL;
        root = p;
        return;
    }else{
        while(temp != NULL){
            r = temp;
            if(key < temp -> data){
                temp = temp -> lchild;
            }else if(key > temp -> data){
                temp = temp -> rchild;
            }else{
                return;
            }
        }
        p = (Node *)malloc(sizeof(Node));
        p -> data = key;
        p -> lchild = p -> rchild = NULL;

        if(key < r -> data) r -> lchild = p;
        else r -> rchild = p;
    }
}

Node *RInsert(Node *p, int key){
    if(p == NULL){
        Node *t = (Node *)malloc(sizeof(Node));
        t -> data = key;
        t -> lchild = t -> rchild = NULL;
        return t;
    }
    if(key < p -> data){
        p -> lchild = RInsert(p -> lchild, key);
    }else if(key > p -> data){
        p -> rchild = RInsert(p -> rchild, key);
    }
    return p;
}

void Inorder(Node *p){
    if(p){
        Inorder(p -> lchild);
        printf("%d ", p -> data);
        Inorder(p -> rchild);
    }
}

Node *Search(int key){
    Node *temp = root;
    while(temp != NULL){
        if(key == temp -> data){
            return temp;
        }else if(key < temp -> data){
            temp = temp -> lchild;
        }else{
            temp = temp -> rchild;
        }
    }
    return NULL;
}

int Height(Node *p){
    int x, y;
    if( p == NULL ){
        return 0;
    }
    x = Height(p -> lchild);
    y = Height(p -> rchild);
    return x > y ? x + 1 : y + 1;
}

Node *InPre(Node *p){
    while(p && p -> rchild != NULL){
        p = p -> rchild;
    }
    return p;
}

Node *InSucc(Node *p){
    while(p && p -> lchild != NULL){
        p = p -> lchild;
    }
    return p;
}

Node *Delete(Node *p, int key){
    Node *q;
    if(p == NULL){
        return NULL;
    }
    if(p -> lchild == NULL && p -> rchild == NULL){
        if(p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if(key < p -> data){
        p -> lchild = Delete(p -> lchild, key);
    }else if(key > p -> data){
        p -> rchild = Delete(p -> rchild, key);
    }else{
        if(Height(p -> lchild) > Height(p -> rchild)){
            q = InPre(p -> lchild);
            p -> data = q -> data;
            p -> lchild = Delete(p -> lchild, q -> data);
        }else{
            q = InSucc(p -> rchild);
            p -> data = q -> data;
            p -> rchild = Delete(p -> rchild, q -> data);
        }
    }
    return p;
}