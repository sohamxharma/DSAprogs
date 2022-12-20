#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// helping to print the linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// inserting new node at the beginning
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
 
    *head = newNode;
}
 
// reversal of k nodes of linked list
struct Node* reverseK(struct Node** current, int k)
{
    struct Node* prev = NULL;
    int count = 0;
 
   // inserting the required elements and functioning the pushing
    while (*current && count++ < k)
    {
        
        struct Node* next = (*current)->next;
        (*current)->next = prev;
        prev = *current;
        *current = next;
    }
 
   
    return prev;
    //returning to last node
}
 
// actual function which reveses the k elements
struct Node *reverseInGroups(struct Node *head, int k)
{
  
    if (head == NULL) {
        return NULL;
    }
 
   
    struct Node* current = head;
 
    struct Node* prev = reverseK(&current, k);
 
 
    head->next = reverseInGroups(current, k);
 

    return prev;
}
 
int main(void)
{
 
    int use[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(use)/sizeof(use[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        push(&head, use[i]);
    }
 
    head = reverseInGroups(head, 3);
 
    printList(head);
 
    return 0;
}