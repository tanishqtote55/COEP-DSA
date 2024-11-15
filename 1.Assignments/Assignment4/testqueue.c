#include <stdio.h>
#include "queue.h"
#include <string.h>
int main() {
    queue q;
    data d;

    qinit(&q);
    while (1) {
        printf("Enter name (or 'exit' to finish): ");
        // Read name
        scanf("%[^\n]s", d.name);
        getchar();
        
        // Check if the user typed "exit"
        if (strcmp(d.name, "exit") == 0) {
            break; // Exit if the user types 'exit'
        }

        // Prompt for age
        printf("Enter age: ");
        scanf("%u", &(d.age));
        getchar();

        // Enqueue only if the queue is not full
        if (!qfull(&q)) {
            enq(&q, d);
        } else {
            printf("Queue is full, cannot enqueue more data.\n");
        }
    }
    if (qempty(&q)) {
        printf("Queue is empty, no contents to display.\n");
    } else {
        // Display the contents of the queue
        printf("\nQueue contents:\n");
        while (!qempty(&q)) {
            d = deq(&q);
            printf("%s %u\n", d.name, d.age);
        }
    }

    return 0;
}