typedef struct Stack{
    int size;
    int top;
    int *A;
}Stack;

void init_Stack(Stack *st, int size);
void push(Stack *st, int data);
int pop(Stack *st);
int peek(Stack st, int pos);
int stackTop(Stack st);
int isEmpty(Stack st);
int isFull(Stack st);
void display(Stack st);
