typedef struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
}Queue;

void init(Queue *q, int size);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void Display(Queue q);