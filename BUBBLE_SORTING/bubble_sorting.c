/*
* Aim : To sort an integer array using bubble sorting algorithm
*/
#include<stdio.h>

#define size 20

int main () {

	int n;		//no. of elements
	scanf("%d\n", &n);		//entering total no. of elements

	int i = 0;
	int j;
	int temp;	
	int array[size];
	puts("----------BUBBLE SORTING----------");
	printf("\nn = %d\n",n);

	for (int k = 0; k < n; ++k)
	{
		scanf("%d ", &array[k]);
		printf("Array[%d] : %d\n",k, array[k]);
	}

	while (i < n) {

		j = 0;
		while (j < n-1) {

			if (array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}

			j++;

		}

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