#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct CLL{
    node *front, *rear;
}CLL;

void init_CLL(CLL *l);
int isEmpty(CLL *l);
void insert_beg(CLL *l, int d);
void insert_end(CLL *l, int d);
void insert_pos(CLL *l, int d, int pos);
void remove_beg(CLL *l);
void remove_end(CLL *l);
void remove_pos(CLL *l, int pos);
void sort(CLL *l);
void display(CLL *l);