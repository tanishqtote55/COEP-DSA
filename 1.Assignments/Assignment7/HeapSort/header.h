typedef struct heap {
    int *h;
    int size;
    int rear;
} heap;

void init_heap(heap *h, int size);
int parent(int index);
int lchild(int index);
int rchild(int index);
void swap(heap *h, int a, int b);
void print_heap(const heap *h);
void heapify(heap *h, int index);
void heap_sort(heap *h);
void free_heap(heap *h);
void insert_heap(heap *h, int value);