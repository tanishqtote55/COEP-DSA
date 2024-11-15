typedef struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}Node;

typedef struct Queue{
    int size;
    int front;
    int rear;
    Node **Q;
}Queue;
void init(Queue *q, int size);
void enqueue(Queue *q, Node *data);
Node *dequeue(Queue *q);
void Display(Queue q);
int isEmpty(Queue q);


extern struct Node *root;
void Treecreate();
void Preorder(Node *p);
void Inorder(Node *p);
void Postorder(Node *p);


typedef struct Stack {
    int size;
    int top;
    struct Node **S;
} Stack;
void init_Stack(Stack *st, int size);
void push(Stack *st, Node *data);
Node *pop(Stack *st);
int isEmptyStack(Stack st);
int isFull(Stack st);
void IPreorder(Node *p);
void IInorder(Node *p);

void LevelOrder(Node *p);

int count(Node *p);
int height(Node *p);
int countLeafNodes(Node *p);
int countDegree2Nodes(Node *p);
int countDegree1And2Nodes(Node *p);
int countDegree1Nodes(Node *p);