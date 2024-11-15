typedef struct node{
    int data;
    struct node *next;
}node;

typedef node* SLL;

void init_SLL(SLL *head);
void insert_beg(SLL *head, int d);
void insert_end(SLL *head, int d);
void insert_pos(SLL *head, int d, int pos);
int length(SLL *head);
void remove_beg(SLL *head);
void remove_end(SLL *head);
void remove_pos(SLL *head, int pos);
void display(SLL *head);