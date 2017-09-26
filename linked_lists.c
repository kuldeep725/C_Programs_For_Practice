#include<stdio.h>

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

		puts("Enter data : ");
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

	while ( p != NULL ) {

		printf("Data 1 : %d\n", p->data);
		p = p->next;

	}
}

int main () {

	node *start;		//points to the first node
	int n;				//total of elements

	printf("Enter the number of elements : \n");
	scanf("%d", &n);
	start = create (n);
	displayData (start);

	return 0;

}