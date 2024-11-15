typedef struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}Node;

extern Node *root;

void Insert(int key);
Node *RInsert(Node *p, int key); 
void Inorder(Node *p);
Node *Search(int key);
int Height(Node *p);
Node *InPre(Node *p);
Node *InSucc(Node *p);
Node *Delete(Node *p, int key);