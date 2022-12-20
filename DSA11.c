// using selection sort on a linked list

#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}
// for the selection sort-
struct Node* selortion(struct Node* head)
{
    struct Node *x1, *y2, *z3, *w4, *s;
    x1 = y2 = head;
    while (y2->next) {
        z3 = w4 = y2->next;
        while (w4) {
            if (y2->data > w4->data) {
                if (y2->next == w4) {
                    if (y2 == head) {
                        y2->next = w4->next;
                        w4->next = y2;
                        s = y2;
                        y2 = w4;
                        w4 = s;
                        z3 = w4;
                        head = y2;
                        w4 = w4->next;
                    }
                    else {
                        y2->next = w4->next;
                        w4->next = y2;
                        x1->next = w4;
                        s = y2;
                        y2 = w4;
                        w4 = s;
                        z3 = w4;
                        w4 = w4->next;
                    }
                }
                else {
                    if (y2 == head) {
                        s = y2->next;
                        y2->next = w4->next;
                        w4->next = s;
                        z3->next = y2;
                        s = y2;
                        y2 = w4;
                        w4 = s;
                        z3 = w4;
                        w4 = w4->next;
                        head = y2;
                    }
                    else {
                        s = y2->next;
                        y2->next = w4->next;
                        w4->next = s;
                        z3->next = y2;
                        x1->next = w4;
                        s = y2;
                        y2 = w4;
                        w4 = s;
                        z3 = w4;
                        w4 = w4->next;
                    }
                }
            }
            else {
                z3 = w4;
                w4 = w4->next;
            }
        }
        x1 = y2;
        y2 = y2->next;
    }
    
    return head;
}
void show(struct Node* head)
{
    while (head) {
        printf("%d->",head->data);
        head = head->next;
    }
}
int main()
{
   struct Node* head = newNode(5);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head = selortion(head);
    show(head);
    return 0;
}