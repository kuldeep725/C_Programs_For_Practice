 #include<stdio.h>

#define size 100
int a[size];
#define RED "\033[31m"
#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[40m"

void merge (int, int, int);
void sort (int, int);

int main () {

	int start_index = 0;
	int max_index;
	scanf("%d\n", &max_index);
	max_index--;
	int i;
	puts(BOLDRED "---------MERGE SORTING----------\n"RESET);
	puts(BOLDRED"LIST BEFORE SORTING : "RESET);

	for (i = 0; i <= max_index; i++) {

		scanf("%d ", &a[i]);
		printf("%d ", a[i]);

	}
	printf(BOLDRED "\nOPERATIONS FOR MERGE SORTING :\n"RESET);
	sort(start_index, max_index);

	puts(BOLDRED"LIST AFTER SORTING : "RESET);

	for(i = 0; i <= max_index; i++) {
		printf("%d ", a[i]);
	}
	puts("");

	return 0;

}

void sort (int low, int high) {		//low and high are indices 

	int mid;

	if (low < high) {

		mid = (low + high)/2;
		sort(low, mid);
		sort(mid + 1, high);

		merge(low, mid, high);

	}

}

void merge (int low, int mid, int high) {

	int l1;
	int l2;
	int i;
	int b[size];

	for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {

		if (a[l1] <= a[l2]) {
			b[i] = a[l1++];
		}

		else {
			b[i] = a[l2++];
		}

	}

	//checking if elements for first half of array exists and storing it in array 'b'
	//either of two while loops will run
	while (l1 <= mid) {	
		b[i++] = a[l1++];
	}

	//checking if elements for second half of array exists and storing it in array 'b'
	while (l2 <= high) {
		b[i++] = a[l2++];
	}

	//copying elements of array 'b' in array 'a' from index 'low' to index 'high'
	for (i = low; i <= high; i++) {
		a[i] = b[i];
		printf("%d ",a[i]);
	}
	puts("");

}