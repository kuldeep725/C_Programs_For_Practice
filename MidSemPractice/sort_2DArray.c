#include<stdio.h>

int b[20][20];
int a[400];

//program to merge two arrays
void mergeArray (int low, int mid, int high) {

    int c[100];
    int i;
    int length_1;
    int length_2;

    //copying elements from array 'a' in a sorting manner in array 'c'
    for (i = low, length_1 = low, length_2 = mid + 1; length_1 <= mid && length_2 <= high; i++) {

        if (a[length_1] < a[length_2]) {
            c[i] = a[length_1++];
        }

        else {
            c[i] = a[length_2++];
        }
    }

    //only one of two below loops will run
    while (length_1 <= mid) {
        c[i++] = a[length_1++];         //copying remaining elements in c
    }
    while (length_2 <= high) {
        c[i++] = a[length_2++];         //copying remaining elements in c
    }

    for (i = low;  i<= high; i++) {
        a[i] = c[i];            //copying new array 'c' into array 'a'
    }

}

//to mergeSort the given array
void mergeSort (int low, int high) {

    if (low < high) {

        int mid = (low + high) / 2;
        mergeSort (low, mid);               //splitting into left half
        mergeSort (mid + 1, high);          //splitting into right half
        mergeArray (low, mid, high);        //merging the two halves

    }
}

int main () {

	int n;
	int i,j,k = 0;

	printf("SORTING FOR N*N MATRIX \n");
	printf("Enter number of rows/columns : \n");
	scanf ("%d", &n);

	printf("ENTER THE ELEMENTS IN THE MATRIX (%d * %d)\n", n, n);

	for (i = 0; i < n; i++) {

		for (j = 0; j < n; j++) {

			scanf("%d", &b[i][j]);
			a[k++] = b[i][j];

		}

	}

	mergeSort(0, k - 1);            //function to sort the given array

    printf("ARRAY AFTER SORTING IS : \n");

    //printing list after sorting
    for (i = 0; i < k; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;       //returning 0 for successful program


}