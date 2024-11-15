typedef struct {
    int *A;   
    int size; 
    int len;  
} array;

void init(array *arr, int size);
void append(array *arr, int d);
void swap(int *a, int *b);
int partition(array *arr, int low, int high);
void quickSort(array *arr, int low, int high);
void printArray(array *arr);