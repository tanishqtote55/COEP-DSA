typedef struct node{
    int data;
    struct node *next;
}node;

typedef node* SLL;

void init_SLL(SLL *head);
void append(SLL *head);
void traverse(SLL head);
void insert_beg(SLL *head);
void remove_pos(SLL *head, int pos);
void len(SLL head);