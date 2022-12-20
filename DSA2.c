
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
   // hold base adress of this part 
    int* ptr;
    int n, i;
 
    // Input no. of elements from user
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
 
    // using malloc for dynamic allocation
    printf("Enter the interger");
    ptr = (int*)malloc(n * sizeof(int));
 
    // Checking for successful allocation
    if (ptr == NULL) {
        printf("Unsuccessful memory allocation.\n");
        exit(0);
    }
    else {
 
        // Memory allocation using malloc has been a success
        printf("Malloc has been applied. Memory allocation is successful\n");
 
        // separating the elements of the array and obtaining their values
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("Indisvidual elements of the array are:- ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
 
    return 0;
}