#include<stdio.h>
#include<stdlib.h>

typedef struct student {

    int data;
    struct student *next;

} student;

student * createNode (int n) {

    student *head = NULL;
    student *p = (student *) malloc(sizeof(student));
    printf("Enter %d elements : \n", n);
    scanf("%d", &(p->data));
    p->next = NULL;
    head = p;
    student *temp = head;

    int i;
    for (i = 1; i < n; i++) {
        scanf("%d", &(p->data));
        temp->next = p;
        temp = p;
    }
    temp->next = NULL;

    return head;

}

void displayNode (student *head, int n) {

    int i;
    student p = head;
    for (i = 0; i < n; i++) {

        printf("%d  ", p->data);
        p = p->next;

    }

}

void freeMemory (student *head, int n) {

    student *p = head;
    student *temp;

    do {

        temp = p;
        p = p->next;
        temp->next = NULL;
        free(temp);

    } while(p != NULL);

}

int main () {

    student *head = NULL;
    int n;
    printf("Enter the number of elements to be inserted in the linked list :\n");
    scanf("%d", &n);

    head = createNode (n);
    displayNode (head, n);
    printf("Enter the element to be inserted : \n");
    int insertingEle;
    scanf("%d", &insertingEle);
    printf("Enter the element after which element is to be placed :\n");
    int posEle;
    scanf("%d", &posEle);

    return 0;

}
