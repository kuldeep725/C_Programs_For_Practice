/*
* Aim : To sort an integer array using insertion sorting algorithm
*/
#include<stdio.h>

#define size 1000

void insertionSort (int *array, int n) {

	int i = 1;
	int j;
	int key;

	while (i < n) {

		j = i - 1;

		key =  array[i];

		while (j >= 0 && key < array[j]) {

			array[j+1] = array[j];
			j--;

		}
		array[j+1] = key;
		i++;

		//First loop time information
		/*
		real	0m0.147s
		user	0m0.000s
		sys		0m0.000s
		*/

		//The loop below is longer.
/*
		while (j >= 0) {

			if (array[index] < array[j]) {

				temp = array[index];
				array[index] = array[j];
				array[j] = temp;
				index = j;

			}
			j--;

		}
		i++;*/
		//Second loop time information
		/*
		real	0m0.148s
		user	0m0.000s
		sys		0m0.000s
		*/

		

	}

}

int main () {

	int n;		//no. of elements
	scanf("%d\n", &n);		//entering total no. of elements
	
	int array[size];
	puts("----------INSERTION SORTING----------");
	printf("\nn = %d\n",n);

	for (int k = 0; k < n; ++k)
	{
		scanf("%d ", &array[k]);
		printf("Array[%d] : %d\n",k, array[k]);
	}

	insertionSort(array, n);

	printf("\nSORTED ARRAY : \n");

	for (int i = 0; i < n; ++i)
	{
		printf("%d, ",array[i] );
	}
	puts("");

	return 0;
}