typedef struct {
    int top;
    char *arr;
} Stack;

void init(Stack *s, int size);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
char pop(Stack *s);
char peek(Stack *s);
void reverseString(char exp[]);