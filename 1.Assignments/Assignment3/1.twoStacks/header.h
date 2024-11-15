typedef struct twoStacks {
    int* arr;    
    int size;    
    int top1;    
    int top2;    
}twoStacks;

void init(twoStacks *ts, int size);

void push1(twoStacks *ts, int x);
void push2(twoStacks *ts, int x);

int pop1(twoStacks *ts);
int pop2(twoStacks *ts);

void display1(twoStacks *ts);
void display2(twoStacks *ts);