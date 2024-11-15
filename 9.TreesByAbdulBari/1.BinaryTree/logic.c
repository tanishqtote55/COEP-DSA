#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct Node *root = NULL;   

void init(Queue *q, int size){
    q -> size = size;
    q -> front = 0;
    q -> rear = 0;
    q -> Q = (Node **)malloc(sizeof(Node *) * size);
}

void enqueue(Queue *q, Node *data){
    if((q -> rear + 1) % (q -> size) == q -> front){
        printf("Queue is full\n");
    }else{
        q -> rear = (q -> rear + 1) % (q -> size);
        q -> Q[q -> rear] = data;
    }
}

Node *dequeue(Queue *q){
    if(q -> front == q -> rear){
        printf("Queue is Empty\n");
        return NULL;
    }else{
        Node *x;
        q -> front = (q -> front + 1) % (q -> size);
        x = q -> Q[q -> front];
        return x;
    }
}

void Display(Queue q){
    int i = q.front + 1;
    do{
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    }while(i != (q.rear + 1) % (q.size));
    printf("\n");
}

int isEmpty(Queue q){
    return q.front == q.rear;
}


void Treecreate(){
    struct Node *p, *t;
    int x;
    Queue q;
    init(&q,100);

    printf("Enter root value ");
    scanf("%d",&x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root -> data = x;
    root -> lchild = root -> rchild=NULL;
    enqueue(&q, root);

    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("eneter left child of %d ", p -> data);
        scanf("%d", &x);
        if(x != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            enqueue(&q, t);
        }
        printf("eneter right child of %d ",p -> data);
        scanf("%d",&x);
        if(x != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> rchild = t;
            enqueue(&q, t);
        }
    }
}

void Preorder(Node *p){
    if(p){
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}


// Use of Stack for Iterative Traversal
void init_Stack(Stack *st, int size){
    st -> size = size;
    st -> top = -1;
    st -> S = (Node **)malloc(sizeof(Node *) * (st -> size));
}

void push(Stack *st, Node *data){
    if(st -> top == st -> size - 1){
        printf("Stack Overflow\n");
    }else{
        st -> top++;
        st -> S[st -> top] = data;
    }
}

Node *pop(Stack *st){
    if(st -> top == -1){
        printf("Stack Underflow\n");
        return NULL;
    }else{
        Node *x = NULL;
        x = st -> S[st -> top];
        st -> top--;
        return x;
    }
}

int isEmptyStack(Stack st){
    if(st.top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack st){
    if(st.top == st.size - 1){
        return 1;
    }else{
        return 0;
    }
}

void IPreorder(Node *p){
    Stack stk;
    init_Stack(&stk, 100);
    while(p || !isEmptyStack(stk)){
        if(p){
            printf("%d ", p -> data);
            push(&stk, p);
            p = p -> lchild;
        }else{
            p = pop(&stk);
            p = p -> rchild;
        }
    }
}

void IInorder(Node *p){
    Stack stk;
    init_Stack(&stk, 100);
    while(p || !isEmptyStack(stk)){
        if(p){
            
            push(&stk, p);
            p = p -> lchild;
        }else{
            p = pop(&stk);
            printf("%d ", p -> data);
            p = p -> rchild;
        }
    }
}


// Level Order Traversal
void LevelOrder(Node *root){
    Queue q;
    init(&q, 100);
    printf("%d ", root -> data);
    enqueue(&q, root);

    while(!isEmpty(q)){
        root = dequeue(&q);
        if(root -> lchild){
            printf("%d ", root -> lchild -> data);
            enqueue(&q, root -> lchild);
        }
        if(root -> rchild){
            printf("%d ", root -> rchild -> data);
            enqueue(&q, root -> rchild);
        }
    }
}

int count(Node *p){
    
    if(p != NULL){
        return count(p -> lchild) + count(p -> rchild) + 1;
    }
    return 0;
}

int height(Node *p){
    int x, y;
    if(p == 0){
        return 0;
    }
    x = height(p -> lchild);
    y = height(p -> rchild);
    if(x > y){
        return x + 1;
    }else{
        return y + 1;
    }
}   

int countLeafNodes(Node *p){
    int x, y;
    if(p != NULL){
        x = countLeafNodes(p -> lchild);
        y = countLeafNodes(p -> rchild);
        if(p -> lchild == NULL && p -> rchild == NULL){
            return x + y + 1;
        }
        else{
            return x + y;
        }
    }
    return 0;
}   

int countDegree2Nodes(Node *p){
    int x, y;
    if(p != NULL){
        x = countDegree2Nodes(p -> lchild);
        y = countDegree2Nodes(p -> rchild);
        if(p -> lchild != NULL && p -> rchild != NULL){
            return x + y + 1;
        }
        else{
            return x + y;
        }
    }
    return 0;
}   

int countDegree1And2Nodes(Node *p){
    int x, y;
    if(p != NULL){
        x = countDegree1And2Nodes(p -> lchild);
        y = countDegree1And2Nodes(p -> rchild);
        if(p -> lchild != NULL || p -> rchild != NULL){
            return x + y + 1;
        }
        else{
            return x + y;
        }
    }
    return 0;
}   

int countDegree1Nodes(Node *p){
    int x, y;
    if(p != NULL){
        x = countDegree1Nodes(p -> lchild);
        y = countDegree1Nodes(p -> rchild);
        // p -> lchild != NULL ^ p -> rchild != NULL => Exlusive OR
        if((p -> lchild != NULL && p -> rchild == NULL) || (p -> lchild == NULL && p -> rchild != NULL)){
            return x + y + 1;
        }
        else{
            return x + y;
        }
    }
    return 0;
}  