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

void infixToPostfix(char* infix, char* postfix);
int evaluatePostfix(char* postfix);

void reverseString(char* str);
void replaceParentheses(char* expr);
void infixToPrefix(char* infix, char* prefix);