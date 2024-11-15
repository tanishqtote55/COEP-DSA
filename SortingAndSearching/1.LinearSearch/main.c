#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

int main(){
	array a;
	int key, pos;
	init(&a, 5);
	append(&a, 5);
	append(&a, 8);
	append(&a, 9);
	append(&a, 2);
	append(&a, 3);
	
	printf("Enter key to search (Linear Search): ");
	scanf("%d", &key);
    pos = linearSearch(&a, key);
    if (pos != -1) printf("Key found at index %d\n", pos);
    else printf("Key not found\n");
	
	return 0;
}