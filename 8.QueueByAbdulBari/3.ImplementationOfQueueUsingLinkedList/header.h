typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    struct Node *front;
    struct Node *rear;
}Queue;

void init(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void Display(Queue q);