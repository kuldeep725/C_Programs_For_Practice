/*
* Aim : To sort an integer array using shell sorting algorithm
*/
#include<stdio.h>

#define size 1000

void shellSort (int *a, int n) {

	int i = 0;
	int j = n / 2;
	int temp;

	while (i < n / 2) {

		if (a[j] < a[i]) {

			temp = a[i];
			a[i] = a[j];
			a[j] = temp;

		}
		i++;
		j++;

	}

}

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

	}

}

int main () {

	int n;		//no. of elements
	scanf("%d\n", &n);		//entering total no. of elements
	
	int array[size];
	puts("----------SHELL SORTING----------");
	printf("\nn = %d\n",n);

	for (int k = 0; k < n; ++k)
	{
		scanf("%d ", &array[k]);
		printf("Array[%d] : %d\n",k, array[k]);
	}

	shellSort(array, n);
	insertionSort(array, n);

	printf("\nSORTED ARRAY : \n");

	for (int i = 0; i < n; ++i)
	{
		printf("%d, ",array[i]);
	}
	puts("");

	return 0;
}
/*SHELL SORTING WITH ARRAY 80
real	0m0.145s
user	0m0.000s
sys		0m0.000s

*/
