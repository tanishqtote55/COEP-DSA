typedef struct{
    int top;
    int arr[100];
}Stack;

void init(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int x);
int pop(Stack *s);
void decimalToBinary(int number);