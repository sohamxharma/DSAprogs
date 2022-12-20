
// algorithm for insertion sort in an array
#include <math.h>
#include <stdio.h>
 //insortion stands for insertion sort
 //k stands for key
void insortion(int array[], int n)
{
    int i, k, j;
    for (i = 1; i < n; i++) 
    {
        k = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > k) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = k;
    }
}
 
// A utility function to print an array of size n
void printer(int array1[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", array1[i]);
    printf("\n");
}
 
/* Driver program to test insertion sort */
int main()
{
    int array1[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(array1) / sizeof(array1[0]);
 
    insortion(array1, n);
    printer(array1, n);
    return 0;
}