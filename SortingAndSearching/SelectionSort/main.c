#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

int main(){
	array a;
	init(&a, 5);
	append(&a, 5);
	append(&a, 8);
	append(&a, 9);
	append(&a, 2);
	append(&a, 3);
	
	printf("Unsorted array: \n");
    print_array(&a);
    	
	selection_sort(&a);
	
	printf("Sorted array: \n");
    print_array(&a);
	
	return 0;
}