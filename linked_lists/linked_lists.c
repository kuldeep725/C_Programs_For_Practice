#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	
	int data;
	struct node *next;

} node ;

node*  create ( int m ) {

	node *start = NULL;		//points to the first node
	node *p;
	node *end;				//points to the last node

	int data;
	int i;
	for ( i = 0; i < m; i++ ) {

		p = (node *) malloc(sizeof(node));

		//puts("Enter data : ");
		scanf("%d",&data);
		p->data = data;

		if ( start == NULL ) {
			start = p;
			end = p;
		}

		else {
			end->next = p;
			end = p;
		}

	}

	return start;

}

void displayData ( node *p ) {

	int i = 0;
	while ( p != NULL ) {

		printf("Data %d : \"%d\"\n", ++i, p->data);
		p = p->next;

	}
}

void freeNode (node *p) {

	node *temp = (node *) malloc( sizeof(node));

	while ( p != NULL ) {

		temp = p->next;
		free(p);
		p = temp;

	}
	free(temp);

}
int main () {

	node *start;		//points to the first node
	int n;				//total of elements

	//printf("Enter the number of elements : \n");
	scanf("%d", &n);
	start = create (n);
	displayData (start);
	freeNode(start);

	return 0;

}