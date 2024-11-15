// Data structure to hold the information
typedef struct data {
    char name[16];
    unsigned int age;
} data;

// Node structure for the queue
typedef struct node {
    data value;
    struct node *next;
} node;

// Queue structure
typedef struct {
    node *head;
    node *tail;
} queue;

void qinit(queue *q);
int qfull(queue *q);
int qempty(queue *q);
void enq(queue *q, data d);
data deq(queue *q);