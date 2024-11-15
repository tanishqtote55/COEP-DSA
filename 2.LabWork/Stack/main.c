#include "header.h"

int main(){
    stack s;
    int choice, element, size, index;
    while(1){
        printf("\nStack Menu\n");
        printf("1. init\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Stack Top\n");
        printf("5. Peek at specific index\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter the size of the stack: ");
                scanf("%d", &size);
                init(&s, size);
                break;
            case 2:
                if(!isFull(s)){
                    printf("Enter the element to push: ");
                    scanf("%d", &element);
                    push(&s, element);
                }
                else{
                    printf("Stack is Full\n");
                }
                break;
            case 3:
                if(!isEmpty(s)){
                    printf("Popped element is: %d\n", pop(&s));
                }
                else{
                    printf("Stack is empty\n");
                }
                break;
            case 4:
                if(!isEmpty(s)){
                    printf("Stack Top element is: %d\n", stackTop(s));
                }
                else{
                    printf("Stack is empty\n");
                }
                break;
            case 5:
                if(!isEmpty(s)){
                    printf("Enter the index to peek from stack: ");
                    scanf("%d", &index);
                    peek(&s, index);
                }
                else{
                    printf("Stack is empty\n");
                }
                break;
            case 6:
                display(s);
                break;
            case 7:
                printf("Exiting...\n");
                free(s.a);
                exit(0);
                break;
            default:
                printf("Invalid Choice, Try again!\n");
        }
    }

    return 0;
}