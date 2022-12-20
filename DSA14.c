// Heap Builder from Array
 
#include <stdio.h>
 

void swapper(int *a, int *b)
{
    int temp = *a;
      *a = *b;
      *b = temp;
}
 
void heapper(int arr[], int N, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 

    if (l < N && arr[l] > arr[largest])
        largest = l;
 

    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    
    if (largest != i) {
        swapper(&arr[i], &arr[largest]);
 

        heapper(arr, N, largest);
    }
}
 

void heapbilder(int arr[], int N)
{
    
    int startIdx = (N / 2) - 1;
 
    
    for (int i = startIdx; i >= 0; i--) {
        heapper(arr, N, i);
    }
}
 

void heaprinter(int arr[], int N)
{
    printf("Array representation of Heap is:\n");
 
    for (int i = 0; i < N; ++i)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
 
    int N = sizeof(arr) / sizeof(arr[0]);
 
    
    heapbilder(arr, N);
    heaprinter(arr, N);
   

    return 0;
}
//for sorting we can use the sorting as done in the previous DSA.c files
