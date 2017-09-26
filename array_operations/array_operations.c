/*
* Name : Kuldeep Singh Bhandari
* Date : Saturday, 7 July 2017
* Task : To insert or delete an item from an array
*/

#include<stdio.h>

#define size 100

void insert (int *array, int *n, int ele, int pos) {

	int i;
	int m = *n;

	for ( i = m; i >= pos+1; i-- )
		array[i] = array[i-1];

	array[pos] = ele;
	*n += 1;

	printf("The element '%d' is inserted in the position : '%d'\n", ele, pos);
}

void delete (int *array, int *n, int pos) {

	int i;
	int m = *n;
	printf("The Element '%d' is deleted from position : '%d'\n", array[pos], pos + 1);

	for ( i = pos; i < m-1; i++ ) 
		array[i] = array[i + 1];

	*n -= 1;
	
}

void displayArray (int *array, int n) {

	int i;
	puts("The Elements Of The Array Are : ");
	for ( i = 0; i < n; i++ ) 
		printf("%d ", array[i]);		//printing the elements in the array
	puts("");
}

int main () {

	int array[size];
	int n;
	int pos;
	int i;

	scanf("%d\n", &n);		//entering number of elements in the array

	for ( i = 0; i < n; i++ ) 
		scanf("%d ",&array[i]);		//entering elements in the array

	displayArray(array, n);	

	char check_loop = 'y';

	do {

		/*printf("\n----------Choose The Operation----------\n");
		printf("1. Insert An Item\n");
		printf("2. Delete An Item\n");
		printf("3. End The Program\n");
		printf("------------------------------------------\n");*/

		//printf("Your choice --> ");
		int choice;
		scanf("%d\n", &choice);

		switch ( choice ) {

			case 1 : 
					//printf("Enter The Element To Be Inserted : ");

					;		/*  because of the error
							 *	array_operations.c:65:6: error: a label can only be part of a statement 
							 *	and a declaration is not a statement
     						 *	int ele;*/

					int ele;
					scanf("%d\n", &ele);

					//printf("Enter The Position For New Element '%d' : ", ele);
					scanf("%d\n", &pos);

					if ( pos > n || pos < 0 ) {
						printf("Invalid Position : %d\n", pos);
						break;
					} 

					insert(array, &n, ele, pos);
					displayArray(array, n);
					break;

			case 2 :
					;

					scanf("%d\n", &pos);

					if ( pos > n || pos < 0 ) {
						printf("Invalid Position : %d\n", pos);
						break;
					} 

					delete(array, &n, pos);
					displayArray(array, n);
					break;

			case 3 : 
					puts("All Operations Are Finished Now !!");
					displayArray(array, n);
					check_loop = 'n';
					break;

			default :
					puts("Invalid Input");
					break;

		}
	} while ( check_loop == 'y');
	



}