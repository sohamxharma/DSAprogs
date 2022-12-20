// quick sort on a single linked list

#include <stdio.h>
#include <stdlib.h>
 
// node structure

struct Node {
    int data;
    struct Node* next;
};
 
// adding node at the edn
void insert(struct Node** head, int value)
{
    // Chozetsu dynamic
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        
        printf("Memory overflow\n");
    }
    else {
        node->data = value;
        node->next = NULL;
        if (*head == NULL) {
            *head = node;
        }
        else {
            struct Node* temp = *head;
 
            // final node finder
            while (temp->next != NULL) {
                temp = temp->next;
            }
 
            // node adder at the end
            temp->next = node;
        }
    }
}
 
// Displaying linked list element
void displayer(struct Node* head)
{
    if (head == NULL) {
        printf("Empty linked list");
        return;
    }
    struct Node* temp = head;
    printf("\n Linked List :");
    while (temp != NULL) {
        printf("  %d", temp->data);
        temp = temp->next;
    }
}
 
// Finding last node of linked list
struct Node* last_node(struct Node* head)
{
    struct Node* tempor = head;
    while (tempor != NULL && tempor->next != NULL) {
        tempor = tempor->next;
    }
    return tempor;
}
 
// We are Setting the given last node position to its proper
// position
struct Node* parition(struct Node* priori, struct Node* last)
{
    // Get first node of given linked list
    struct Node* pivot = priori;
    struct Node* front = priori;
    int tempor = 0;
    while (front != NULL && front != last) {
        if (front->data < last->data) {
            pivot = priori;
 
            // Swapping  node values
            tempor = priori->data;
            priori->data = front->data;
            front->data = tempor;
 
            // Visiting the next node
            priori = priori->next;
        }
 
        // Visiting the next node
        front = front->next;
    }
 
    // Change last node value to current node
    tempor = priori->data;
    priori->data = last->data;
    last->data = tempor;
    return pivot;
}
 
// Performing quick sort in  the given linked list
void quicksorter(struct Node* first, struct Node* last)
{
    if (first == last) {
        return;
    }
    struct Node* pivot = parition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}
 
// Driver's code
int main()
{
    struct Node* head = NULL;
 
    // Create linked list
    insert(&head, 35);
    insert(&head, 52);
    insert(&head, 34);
    insert(&head, 63);
    insert(&head, 4);
    insert(&head, 97);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 1);
    printf("\n prior to the function operation:: ");
    display(head);
 
    // caller of  function
    quicksorter(head, last_node(head));
    printf("\n After Sort ");
    displayer(head);
    return 0;
}