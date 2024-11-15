typedef struct{
	int *A;
	int size;
	int len;
}array;

void init(array *arr, int size);
void append(array *arr, int d);
void selection_sort(array *arr);
void print_array(array *arr);