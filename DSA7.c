// creating a BST from an int array

#include<stdio.h>
#include<stdlib.h>
 
// BST node
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};
 
struct TNode* newNode(int data);
 
// function to create a balanced binary tree
struct TNode* sortedArrayToBST(int arr[], int start, int end)
{
    //first or base
    if (start > end)
      return NULL;
 
    // getting the 1/2 element
    int half = (start + end)/2;
    struct TNode *root = newNode(arr[half]);
 
    // creates left child
    root->left =  sortedArrayToBST(arr, start, half-1);
 
    // creates right child recursively
    root->right = sortedArrayToBST(arr, half+1, end);
 
    return root;
}
 
// allocating new nodes
struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)
    malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
// preorder for the Binary search tree
void preOrder(struct TNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
 
// main program
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct TNode *root = sortedArrayToBST(arr, 0, n-1);
    printf("The n for preorder transversal is as.. ");
    preOrder(root);
 
    return 0;
}