#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
     int data;
     struct Node *next;
} Node;
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    if (head == NULL) {
        head = (Node *) malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
    }
    else {
        Node *p = head;
        Node *temp = NULL;
        int i = 0;
        while (p->next != NULL) {
            
            if (i == position) {
                break;
            }
            i++;
            temp = p;
            p = p->next;
            
        }
        //printf("%d", p->data);
        Node *q = (Node *) malloc(sizeof(Node));
        q->next = p;
        q->data = data;
        if (temp != NULL)
            temp->next = q;
        
    }
    return head;
}