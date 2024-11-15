#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next, *prev;
}node;

typedef struct DLL{
    node *front, *rear;
}DLL;

void init_DLL(DLL *l);
int len(DLL *l);
int isEmpty(DLL *l);
void insert_beg(DLL *l, int d);
void insert_end(DLL *l, int d);
void insert_pos(DLL *l, int d, int index);
void remove_beg(DLL *l);
void remove_end(DLL *l);
void remove_pos(DLL *l, int index);
void sort(DLL *l);
void displayLR(DLL l);
void displayRL(DLL l);
void is_palindrome(DLL *l);
void remove_duplicates(DLL *l);