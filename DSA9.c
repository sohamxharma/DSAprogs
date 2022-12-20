// selection sort program
#include <stdio.h>
 
void replacer(int *p1, int *p2)
{
    int t= *p1;
    *p1 = *p2;
    *p2 = t;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, mini;
 
     
    for (i = 0; i < n-1; i++)
    {
        // mini element
        mini = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[mini])
            mini = j;
 
        // use of replacer funtion
           if(mini!= i)
            replacer(&arr[mini], &arr[i]);
    }
}
 
//array printer function
void printArray(int arr[], int range)
{
    int i;
    for (i=0; i < range; i++)
    printf("%d ", arr[i]);
    printf("\n");
}
 
// main function
int main()
{
    int array[] = {64, 25, 12, 22, 11};
    int n = sizeof(array)/sizeof(array[0]);
    selectionSort(array, n);
    printf("Sorted array: \n");
    printArray(array, n);
    return 0;
}