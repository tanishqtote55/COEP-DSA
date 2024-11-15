#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    array a, b, *c = NULL;
    int choice, index;
    do {
        printf("\nMenu:\n");
        printf("1. init()\n");
        printf("2. append()\n");
        printf("3. insert_at_index()\n");
        printf("4. remove_at_index()\n");
        printf("5. display()\n");
        printf("6. max()\n");
        printf("7. min()\n");
        printf("8. reverse()\n");
        printf("9. merge()\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                init(&a, 10);
                break;
            case 2:
                append(&a, rand() % 100);
                break;
            case 3:
                printf("Enter index of element to insert: ");
                scanf("%d", &index);
                insert_at_index(&a , index, rand() % 100);
                break;
            case 4:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                remove_at_index(&a, index);
                break;
            case 5:
                display(&a);
                break;
            case 6:
                printf("Maximum element: %d\n", max(a));
                break;
            case 7:
                printf("Minimum element: %d\n", min(a));
                break;
            case 8:
                reverse(&a);
                break;
            case 9:
                init(&b, 10);
                for(int i = 0; i < b.size; i++){
                    b.A[i] = rand() % 100;
                }
                b.length = b.size;
                printf("First Array : ");
                display(&a);
                printf("\nSecond Array : ");
                display(&b);
                printf("\nMerged Array : ");
                c = merge(&a, &b);
                display(c);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}