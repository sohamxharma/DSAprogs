
#include <iostream>
using namespace std;
  
  //nodal representation
struct Node {
    int data;
    Node* next;
};
  
// to insert a node
void insert(Node** root, int item)
{
    Node* temp = new Node;
    Node* ptr;
    temp->data = item;
    temp->next = NULL;
  
    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
  
void display(Node* root)
{
    while (root != NULL) {
        cout << root->data << " ";
        root = root->next;
    }
}
  
Node *arrayToList(int arr[], int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
   return root;
}
  
// code driver
int main()
{
    int n1;
   


    int i; 
    printf("Enter the size of the array: "); 
    scanf("%d",&n1); 
    int a[n1]; 
    printf("\n"); 
    for(i=0;i<n1;i++) 
    { 
    printf("Enter %d elements of the array: ",i+1); 
    scanf("%d",&a[i]); 
    }

    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = arrayToList(arr, n);
    display(root);
    return 0;
}
