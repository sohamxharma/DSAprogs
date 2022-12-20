//deletion of nodes in a single linked list
#include <stdio.h>
#include <stdlib.h>
 

struct Node {
    int data;
    struct Node* next;
};
 
// pointer refernce to the head
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 

void deleteNode(struct Node** head_ref, int key)
{
    // temp storage of head node
    struct Node *tempor = *head_ref, *prev;
 

    if (tempor != NULL && tempor->data == key) {
        *head_ref = tempor->next; 
        free(tempor); 
        return;
    }
 
// loop searching the key to be removed
    while (tempor != NULL && tempor->data != key) {
        prev = tempor;
        tempor = tempor->next;
    }
 
    // If key was not present in linked list
    if (tempor == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = tempor->next;
 
    free(tempor); // Free memory
}
 
// This function prints contents of linked list starting
// from the given node
void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}
 
// Driver code
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 1);
    puts("linked list after removing 1:");


    printList(head);
    return 0;
}