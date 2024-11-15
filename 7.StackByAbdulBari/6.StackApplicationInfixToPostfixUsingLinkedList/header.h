typedef struct Node{
    char data;
    struct Node *next;
}Node;

typedef struct Stack {
    Node* top;
} Stack;

void init_Stack(Stack* st);
void push(Stack* st, char data);
char pop(Stack* st);
int peek(Stack st, int pos);
int stackTop(Stack st);
int isEmpty(Stack st);
int isFull();
void display(Stack st);

int isBalanced(char *exp);

int pre(char x);
int isOperand(char x);
char *infixToPostfix(char *infix);