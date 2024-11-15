#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main(){
    Array a;
    int size, n;

    printf("Array ADT Program\n");
    printf("Enter the size of the Array: ");
    scanf("%d", &size);
    init(&a, size);
    
    do{
        printf("\nChoice 1:- apprend\nChoice 2:- Display\nChoice 3:- Insert At Index\nChoice 4:- Remove From Index\nChoice 5:- Max Element\nChoice 6:- Min element\nChoice 7:- reverse\nChoice 8:- Merge Two array Array\nChoice 0: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the value to append: ");
            int value;
            scanf("%d", &value);
            append(&a, value);
            break;
        case 2:
            printf("Array: ");
            display(&a);
            break;
         case 3:
            printf("Enter the value and index to append: ");
        int value1, ind;
        scanf("%d%d", &value1, &ind);
        
        // Call the insert_at_index function
        insert_at_index(&a, ind, value1);
        break;
         case 4:
            printf("Enter the  index to Delete: ");
            int  ind1;
            scanf(" %d",  &ind1);
            remove_at_index(&a,ind1);
            break;
        case 5:
            printf("Max element in array : %d", maxele(&a));
        break;
        case 6:
            printf("Min element in array : %d", minele(&a));
        break;
        case 7: 
                printf("list: ");
                display(&a);
                reverse(&a);
                printf("Reverse list: ");
                display(&a);
        break;

        case 8:
            printf("Before Merging Array ");
            display(&a);
            printf("Merged Array ");
            merge(&a, &a);
            display(&a);
        break;

        case 0:
            printf("Exiting program.\n");
            break;
        
        default:
            printf("\nWrong Choice");
            break;
        }

    }while(n != 0);
}