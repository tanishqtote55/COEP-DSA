typedef struct {
    int top;
    int arr[100];
} Stack;

void init(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int precedence(char op);
int isLeftAssociative(char op);
void infixToPostfix(char* infix, char* postfix);
int evaluatePostfix(char* postfix);

