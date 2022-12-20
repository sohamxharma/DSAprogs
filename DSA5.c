
// project 5 to reverse a linked list using the head pointer only
#include <stdio.h>
#include <stdlib.h>
 
// node of linked list
struct Node {
    int data;
    struct Node* next;
};
 
// block which reverses the linked list
static void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) 
    {
        
    next = current->next;
 
        // exchanging pointer
    current->next = prev;
 
   
    prev = current;
    current = next;
    }
    *head_ref = prev;
}
 

void push(struct Node** head_ref, int new_data)
{
    struct Node* node_2
        = (struct Node*)malloc(sizeof(struct Node));
    node_2->data = new_data;
    node_2->next = (*head_ref);
    (*head_ref) = node_2;
}
 
// printing. .
void printList(struct Node* head)
{
    struct Node* tempor = head;
    while (tempor != NULL) {
        printf("%d ", tempor->data);
        tempor = tempor->next;
    }
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);
 
    printf("linked list given\n");
    printList(head);
    reverse(&head);
    printf("\nNew reversedlinked list \n");
    printList(head);
    getchar();
}