typedef struct array{
    int *A;
    int size;
    int length;
}array;

void init(array *a, int size);
void append(array *a, int element);
void insert_at_index(array *a, int position, int element);
void remove_at_index(array *a, int position);
void display(array *a);
int max(array a);
int min(array a);
void reverse(array *a);
array *merge(array *a, array *b);
