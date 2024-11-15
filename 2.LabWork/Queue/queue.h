// Define the node structure for the list
typedef struct node {
    int data;
    struct node *next;
} node;

// Define the queue structure
typedef struct {
    node *front;
    node *rear;
} queue;

// Function prototypes
void qinit(queue *q);
int qempty(queue *q);
int isqfull();
void enqueue(queue *q, int value);
int dequeue(queue *q);
int peek(queue *q);
void display(queue *q);
