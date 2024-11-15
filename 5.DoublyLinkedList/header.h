typedef struct node{
    int data;
    struct node *next, *prev;
}node;

typedef struct DLL{
    node *head, *tail;
}DLL;

void init_DLL(DLL *l);
int isempty(DLL l);
void insert_right(DLL *l, int d);
void insert_left(DLL *l, int d);
void insert_pos(DLL *l, int d, int pos);
void displayLR(DLL *l);
void displayRL(DLL *l);
int length(DLL *l);
void remove_beg(DLL *l);
void remove_end(DLL *l);
void remove_pos(DLL *l, int pos);
void reverse(DLL *l);
void SortedInsert(DLL *l, int x);
void removelist(DLL *l, int d);
void freelist(DLL *l);
void sort(DLL *l);
int search(DLL l, int d);
DLL listunion(const DLL l1, DLL l2);
DLL intersection(DLL l1, DLL l2);
void removeDuplicates(DLL *l);
