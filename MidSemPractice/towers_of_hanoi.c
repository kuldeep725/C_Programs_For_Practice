#include<stdio.h>

char t1 = 'A';
char t2 = 'B';
char t3 = 'C';
int count = 0;

void tower_of_hanoi (int n, char t1, char t2, char t3) {

	if (n == 1) {
		printf("Move disk 1 from tower %c to tower %c.\n", t1, t3);
		count++;
		return;
	}

	tower_of_hanoi (n-1, t1, t3, t2);
	printf("Move disk %d from tower %c to tower %c.\n", n, t1, t3);
	count++;
	tower_of_hanoi (n-1, t2, t1, t3);

}

int main () {

	int n;
	printf("Enter number of disks : \n");
	scanf("%d", &n);

	tower_of_hanoi(n, t1, t2, t3);
	printf("Total steps taken for %d disks (2^n - 1) : %d\n", n, count);
	return 0;

}