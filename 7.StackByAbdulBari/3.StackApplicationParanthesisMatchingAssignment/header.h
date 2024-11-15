typedef struct {
    int top;
    char arr[100];
} Stack;

void init(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
void pop(Stack *s);
char peek(Stack *s);
int isParanthesisMatched(char char1, char char2);
int paranthesisBalanced(char exp[]);
