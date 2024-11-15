void enqueue(int x){
    push(&s1, x);
}

int dequeue(){
    int x = -1;
    if(isEmpty(s2)){
        if(isEmpty(s1)){
            printf("Queue is Empty");
            return x;
        }else{
            while(!isEmpty(s1)){
                push(&s2, pop(&s1));
            }
        }
        return pop(&s2);
    }
}