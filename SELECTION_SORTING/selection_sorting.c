/*
* Aim : To sort an integer array using selection sorting algorithm
*/
#include<stdio.h>

#define size 20

int main () {

	int n;		//no. of elements
	scanf("%d\n", &n);		//entering total no. of elements

	int i = 0;
	int j;
	int max;
	int index;
	int array[size];
	puts("----------SELECTION SORTING----------");
	printf("\nn = %d\n",n);

	for (int k = 0; k < n; ++k)
	{
		scanf("%d ", &array[k]);
		printf("Array[%d] : %d\n",k, array[k]);
	}

	/*for (int k = 0; k < n; ++k)
	{
		printf("Array[%d] : %d\n",k, array[k]);
	}*/

	int temp;

	while (i < n) {

		j = 0;
		max = array[0];
		index = 0;

		while (j < n-i) {

			if (array[j] > max) {
				max = array[j];
				index = j;
			}
			j++;

		}

		temp = array[index];
		array[index] = array[n-i-1];
		array[n-i-1] = temp;

		/* The drawback of algorithm below is that 
		* it won't work when
		* array[n-i-1] = array[index]
		* i.e. two numbers which are to be swapped have the same value
		*/
		/*array[n-i-1] = array[n-i-1] + array[index];
		array[index] = array[n-i-1] - array[index];
		array[n-i-1] = array[n-i-1] - array[index];*/
		i++;

	}	

	printf("\nSORTED ARRAY : \n");

	for (int i = 0; i < n; ++i)
	{
		printf("%d, ",array[i] );
	}
	puts("");

	return 0;

}