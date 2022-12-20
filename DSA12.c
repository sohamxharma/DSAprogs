
// inserting sort a linked list
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* next;
};
 
struct node* head = NULL;
struct node* sorted = NULL;
 
void push(int val)
{

    struct node* newnode
        = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
 
    newnode->next = head;

    head = newnode;
}
 

void sortesert(struct node* newnode)
{
   
    if (sorted == NULL || sorted->data >= newnode->data) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        struct node* current = sorted;
        
        while (current->next != NULL
               && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
 

void insertionsort()
{
 
    struct node* current = head;
 
   
    while (current != NULL) {
 
        
        struct node* next = current->next;
 
    
        sortedInsert(current);
 
        current = next;
    }

    head = sorted;
}
 
// printer function
void printer(struct node* head)
{
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL");
}
 
// Driver program to test above functions
int main()
{
 
    
    printf("Linked List before sorting:\n");
    printer(head);
    printf("\n");
 
    sortesert(head);
 
    printf("Linked List after sorting:\n");
    printlist(head);
}

