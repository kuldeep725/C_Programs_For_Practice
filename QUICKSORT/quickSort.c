/*
* Aim : To sort an integer array using Quick sorting algorithm
  
  Info : { 
  		   low and high are indices,
  		   two functions are made,
  		   recursion is used 
  		 }
*/
#include<stdio.h>

#define size 1000

//low and high are indices
/*
	low  --> Starting Index
	high --> Ending Index
*/

int partitionArray (int *array, int low, int high) {

	int i;
	int temp; 		//used as temporary variable to swap two elements
	int j = low;

	for (i = low; i <= (high - 1); i++) {

		if (array[i] <= array[high]) {
			
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			j++;

		}

	}

	temp = array[high];
	array[high] = array[j];
	array[j] = temp;

	return j;

}

void quickSort (int *array, int low, int high) {

	int partition;

	if (low < high) {

		partition = partitionArray (array, low, high);

		quickSort (array, low, partition - 1);
		quickSort (array, partition + 1, high);

	}

}

int main () {

	int n;		//no. of elements
	scanf("%d\n", &n);		//entering total no. of elements
	
	int array[size];
	puts("----------QUICK SORTING----------");
	printf("\nn = %d\n",n);

	for (int k = 0; k < n; ++k)
	{
		scanf("%d ", &array[k]);
		printf("Array[%d] : %d\n",k, array[k]);
	}

	quickSort(array, 0, n-1);		//calling quickSort Function to sort array

	printf("\nSORTED ARRAY : \n");

	for (int i = 0; i < n; ++i)
	{
		printf("%d, ",array[i]);
	}
	puts("");

	return 0;
}

/*
QUICK SORTING TIME TAKEN
real	0m0.003s
user	0m0.000s
sys	0m0.000s
*/