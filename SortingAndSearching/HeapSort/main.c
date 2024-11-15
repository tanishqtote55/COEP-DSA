#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    heap h;
    init_heap(&h, 10);
    insert_heap(&h, 12);
    insert_heap(&h, 30);
    insert_heap(&h, 44);
    insert_heap(&h, 2);
    insert_heap(&h, 15);
    insert_heap(&h, 90);
    insert_heap(&h, 62);
    insert_heap(&h, 33);
    heap_sort(&h);
    free_heap(&h);

    return 0;
}