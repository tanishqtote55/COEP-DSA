#include <stdio.h>
#include "queue.h"

int main() {
    queue q;
    int choice, value;

    qinit(&q);

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Check if Queue is Empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front value: %d\n", value);
                }
                break;
            case 4:
                display(&q);
                break;
            case 5:
                if (isqfull()) {
                    printf("The queue is full.\n");
                } else {
                    printf("The queue is not full.\n");
                }
                break;
            case 6:
                if (qempty(&q)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
