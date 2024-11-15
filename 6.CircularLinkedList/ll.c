// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node{
//     int data;
//     struct node *next;
// }node;

// typedef node* list;

// void init(list *l){
//     *l = NULL;
// }

// void append(list *l, int d){
//     node *p = *l;
//     node *nn=(node*)malloc(sizeof(node));
//     if(nn){
//         nn->data = d;
//         nn->next = NULL;
//     }
//     else{
//         return;
//     }

//     if(*l == NULL){
//         *l = nn;
//     }
//     else{
//         while(p->next != NULL){
//             p=p->next;
//         }
//         p->next = nn;
//     }
// }

// void beg(list *l, int d){
//     node *nn = (node*)malloc(sizeof(node));
//     if(nn){
//         nn->data = d;
//         nn->next = *l;
//         *l = nn;
//     }
//     else{
//         return;
//     }
// }

// void end(list *l, int d){
//     node *p = *l;
//     node * nn = (node*)malloc(sizeof(node));
//     if(nn){
//         nn->data=d;
//         nn->next=NULL;
//     }
//     else  
//         return;

//     if(*l==NULL){
//         *l=nn;
//     }
//     else{
//         while(p->next){
//             p=p->next;
//         }
//         p->next = nn;
//     }
    
// }

// int count(list *l){
//     node*p = *l;
//     int count = 0;
//     while(p){
//         count++;
//         p = p->next;
//     }
// }

// void ipos(list *l, int d, int pos){
//     node *p = *l;

//     if(pos < 0 || pos>count(l))
//         return;

//     node *nn = (node*)malloc(sizeof(node));
//     if(nn){
//         nn->data = d;
//         nn->next = NULL;
//     }
//     else
//         return;
    
//     if(pos == 0){
//         nn->next = *l;
//         *l = nn;
//     }
//     else{
//         for(int i = 0; i<pos-1; i++){
//             p=p->next;
//         }
//         nn->next = p->next;
//         p->next = nn;
//     }
// }

// void dbeg(list *l){
//     if(*l){
//         node *p = *l;
//         *l = (*l)->next;
//         free(p);
//     }
//     else  
//         return;
// }

// void dend(list *l) {
//     node *p = *l;
//     node *q = NULL;

//     if (*l == NULL) {
//         return;
//     }

//     if (p->next == NULL) {
//         *l = NULL;
//         free(p);
//         return;
//     }

//     while (p->next) {
//         q = p;
//         p = p->next;
//     }

//     q->next = NULL;
//     free(p);
// }

// void dpos(list *l, int pos){
//     node *p = *l, *q;

//     if(pos < 0 || pos >= count(l))
//         return;
    
//     if(pos == 0){
//         *l = (*l)->next;
//         free(p);
//     }
//     else{
//         for(int i = 0; i < pos - 1; i++){
//             p = p->next;
//         }
//         q = p->next;
//         p->next = q->next;
//         free(q);
//     }
// }

// void display(list *l){
//     node *p = *l;
//     while(p){
//         printf("%d ", p->data);
//         p=p->next;
//     }
//     printf("\n");
// }


// int main() {
//     list l;
//     init(&l);

//     // Inserting elements using different functions
//     append(&l, 10);
//     append(&l, 20);
//     append(&l, 30);
//     printf("After appending 10, 20, 30:\n");
//     display(&l);

//     beg(&l, 5);
//     printf("After inserting 5 at the beginning:\n");
//     display(&l);

//     end(&l, 40);
//     printf("After inserting 40 at the end:\n");
//     display(&l);

//     ipos(&l, 15, 2);
//     printf("After inserting 15 at position 2:\n");
//     display(&l);

//     // Deleting elements using different functions
//     dbeg(&l);
//     printf("After deleting the first element:\n");
//     display(&l);

//     dend(&l);
//     printf("After deleting the last element:\n");
//     display(&l);

//     dpos(&l, 1);
//     printf("After deleting element at position 1:\n");
//     display(&l);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef node* clist; // clist is now a pointer to a node

void init_CLL(clist* l) {
    *l = NULL;
}

void insert_beg(clist* l, int n) {
    node* nn = (node*)malloc(sizeof(node));
    if (nn) {
        nn->data = n;
        if (*l == NULL) {
            *l = nn;
            nn->next = nn;
        } else {
            nn->next = *l;
            node* rear = *l;
            while (rear->next != *l) {
                rear = rear->next;
            }
            rear->next = nn;
            *l = nn; // Update front
        }
    }
}

void insert_end(clist* l, int n) {
    node* nn = (node*)malloc(sizeof(node));
    nn->data = n;

    if (*l == NULL) {
        *l = nn;
        nn->next = nn;
    } else {
        node* rear = *l;
        while (rear->next != *l) {
            rear = rear->next;
        }
        rear->next = nn;
        nn->next = *l;
    }
}

int isempty(clist l) {
    return l == NULL;
}

int Length(clist l) {
    if (l == NULL) return 0;
    int count = 0;
    node* p = l;
    do {
        count++;
        p = p->next;
    } while (p != l);
    return count;
}

void insert_pos(clist* l, int pos, int n) {
    if (pos < 0 || pos > Length(*l)) return;

    node* nn = (node*)malloc(sizeof(node));
    nn->data = n;

    if (pos == 0) {
        insert_beg(l, n);
        return;
    } else {
        node* p = *l;
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }

        nn->next = p->next;
        p->next = nn;

        if (p == *l) { // If inserting at the end
            nn->next = *l;
        }
    }
}

void remove_beg(clist* l) {
    if (*l == NULL) return;

    node* p = *l;
    if (p->next == *l) {
        free(p);
        *l = NULL;
    } else {
        node* rear = *l;
        while (rear->next != *l) {
            rear = rear->next;
        }
        rear->next = p->next;
        *l = p->next;
        free(p);
    }
}

void remove_end(clist* l) {
    if (*l == NULL) return;

    node* p = *l;
    if (p->next == *l) {
        free(p);
        *l = NULL;
    } else {
        while (p->next->next != *l) {
            p = p->next;
        }
        free(p->next);
        p->next = *l;
    }
}

void remove_pos(clist* l, int pos) {
    if (*l == NULL) return;

    int len = Length(*l);
    if (pos < 0 || pos >= len) return;

    if (pos == 0) {
        remove_beg(l);
        return;
    }

    node* p = *l;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
    }

    node* q = p->next;
    p->next = q->next;

    if (q == *l) { // Update front if needed
        *l = p->next;
    }

    free(q);
}

void sort(clist* l) {
    if (*l == NULL || (*l)->next == *l) return;

    int flag;
    node* p;
    node* end = NULL;

    do {
        flag = 0;
        p = *l;

        while (p->next != end && p->next != *l) {
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;

                flag = 1;
            }
            p = p->next;
        }
        end = p;

    } while (flag && end != *l);
}

void Display(clist l) {
    node* p;
    printf("[ ");
    p = l;
    if (!p) {
        printf("]\n");
        return;
    }
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != l);
    printf("]\n");
}
