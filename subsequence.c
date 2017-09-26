/*
 * Name		: Kuldeep Singh Bhandari
 * Program	: Displays the largest strictly increasing contiguous subsequence from the given array
 * Date 		: Tue Jun 27 11:44:02 IST 2017
 */
#include<stdio.h>

int main () {

	int n = 10;
	/*printf("Enter total number of elements in the array : ");
	scanf( "%d", &n);*/

	int input_array[100], i, j, subsequent_array[100][100], count_elements[100], counterForCount = 0;
	int counterForSubsequent = 0; //to store values in columns of subsequent array
	
	printf("Enter the elements in the array : \n");

	for ( i = 0; i < n; i++) 
		scanf("%d", &input_array[i]);	

	puts("");
	puts("The elements in the array are ");
	for ( i = 0; i < n; i++) 
		printf("%d-\"%d\"\n",i, input_array[i]);

	for ( i = 0; i < n; i++) 
		count_elements[i] = 0;

	//loop to store all subsequences in subsequent 2-D array
	for ( i = 0; i < n; i++ ) {

		if ( i != n-1 && input_array[i] > input_array[i+1] ) {

			count_elements[counterForCount]++;
			subsequent_array[counterForCount][counterForSubsequent++] = input_array[i];
			counterForCount++;
			counterForSubsequent= 0;

		}

		else if ( i != n-1 ) {

			if (input_array[i] < input_array[i+1]) {

				count_elements[counterForCount]++;
				subsequent_array[counterForCount][counterForSubsequent++] = input_array[i];

			}		
			else {

				count_elements[counterForCount]++;
				subsequent_array[counterForCount][counterForSubsequent++] = input_array[i];
				counterForCount++;
				counterForSubsequent= 0;

			}
		}
		else if ( i == n-1 && input_array[i] > input_array[i-1] ) {

			count_elements[counterForCount]++;
			subsequent_array[counterForCount][counterForSubsequent++] = input_array[i];

		}

		else if ( i == n-1 && input_array[i] <= input_array[i-1] ) {

			if ( counterForSubsequent != 0 ) {

				counterForCount++;
				counterForSubsequent= 0;

			}

			count_elements[counterForCount]++;
			subsequent_array[counterForCount][counterForSubsequent++] = input_array[i];

		}
		

	}
	printf("THE COUNT ELEMENTS : \n");
	for ( i = 0; i < n; i++) 
		printf("%d  ",count_elements[i]);
	printf("counterForCount : %d\n", counterForCount);

	printf("THE SUBSEQUENT ARRAY : \n");

	for ( i = 0; i < counterForCount+1; i++ ) {
		for ( j = 0; j < count_elements[i]; j++ ) {
			printf("%d  ", subsequent_array[i][j] );
		}
		puts("->");
	}
	puts("");

	int max_index = 0;		//to store index of maximum subsequence
	int number_of_elements_in_winner_array = count_elements[0];

	for ( i = 0; i < n; i++ ) {
		if (count_elements[i] >= count_elements[max_index]) { 
			max_index = i;
			number_of_elements_in_winner_array = count_elements[i];
		}
	}	
	printf("\nThe winner array is : \n");
	for ( i = 0; i < number_of_elements_in_winner_array; i++ ) {
		printf("%d  ", subsequent_array[max_index][i] );
	}
	puts("");

	return 0;

}

/*Sample Output
* 9
* 10
* 3
* 4
* 7
* 9
* 2
* 1 
* 3
*/
