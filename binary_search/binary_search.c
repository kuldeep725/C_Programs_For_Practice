#include<stdio.h>
#include<stdlib.h>

int main () {

	int *array;
	int n, i;
	scanf("%d\n",&n);		//entering the size of the array
	array = (int *) malloc( n * sizeof(int) );

	for ( i = 0; i < n; i++ ) 
		scanf("%d ", &array [i] );		//entering array in the ascending order

	int size = i;				//size of the array
	int search_element;			//element to be searched in the sorted array 

	scanf("%d\n", &search_element);		//entering the element to be searched

	int mid_element = array [size / 2];
	int first_element = array [0];
	int last_element = array [size - 1];
	int first_index = 0;
	int last_index = size - 1;
	int mid_index = size / 2;

	int found = 0;
	int search_index = mid_index;

	if ( first_element == search_element )  {
		found = 1;
		search_index = first_index;
	}
	else if ( last_element == search_element ) {
		search_index = last_index;
		found = 1;
	}
	else {
		while ( first_index != mid_index ) {

			if ( search_element == mid_element ) {

				search_index = mid_index;
				found = 1;
				break;

			}

			else if ( search_element > mid_element ) {

				first_element = mid_element;
				first_index = mid_index;
				mid_index = ( first_index + last_index ) / 2;
				mid_element = array [ mid_index ];

				/*printf("first_element = %d\n", first_element);
				printf("first_index = %d\n", first_index);
				printf("mid_element = %d\n", mid_element);
				printf("mid_index = %d\n", mid_index);*/

			}

			else {

				last_element = mid_element;
				last_index = mid_index;
				mid_index = ( first_index + last_index ) / 2;
				mid_element = array [mid_index];

				/*printf("mid_element = %d\n", mid_element);
				printf("mid_index = %d\n", mid_index);
				printf("last_element = %d\n", last_element);
				printf("last_index = %d\n", last_index);*/

			}
		}
	}

	if ( found )
		printf("The search element '%d' is in the array at the position : %d\n", search_element, search_index + 1);
	
	else 
		printf("The search element '%d' doesn't exist in the array !\n",search_element);
	

	free(array);
	return 0;

}
