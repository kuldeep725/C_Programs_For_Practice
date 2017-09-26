/*
*IMPORTANT INSTRUCTION - USING DYNAMIC ALLOCATION SOMETIMES CAN CAUSE SEGMENTATION FAULT
*/

#include<stdio.h>
#include<string.h>
//#include<stdlib.h>

#define size 100000

int main () {

	long int t;
	char a[size];
	long int i;

	scanf("%ld\n", &t);		//number of test cases
	//printf("t = %d\n", t);

	//a = malloc(size * sizeof(char *));

	/*for (i = 0; i < t; i++) {

		a[i] = (char *) malloc(size * sizeof(char));
		scanf("%s\n", a[i]);		//elements of the array
		//printf("%s\n", a[i]);

	}*/

	long int count;
	long int max = 1;
	i = 1;
	long int k = 0;
	long int signCount = 0;

	for (k = 0; k < t; k++) {

		//a = (char *) malloc(size * sizeof(char));
		scanf("%s\n", a);		//elements of the array

		max = 1;
		i = 1;
		//printf("----------\n");
		for (count = 0; count < strlen(a); count++) {

			if (a[count] == '<') {
				i++;
			}

			if (a[count] == '>') {
				//i--;
				signCount = 1;
				for (; a[count] != '<' && count < strlen(a); count++) {
					if (a[count] == '>') {
						signCount++;
					}
				}
				if (signCount > max) {
					max = signCount;
				}
				count--;
				i = 1;
			}

			if (max < i) {
				max = i;
			}
			//printf("Max for count (%d) = %d\n", count, max);
			/*if (i == 0) {

				if (j == count - 1) {
					maxCheck++;
				}

				else {
					maxCheck = 2;
				}

				if (maxCheck > max) {
					max = maxCheck;
				}
				printf("MaxCheck = %d\n", maxCheck);
				printf("Max = %d\n", max);
				printf("i = %d\n", i);
				i++;
				j = count;

			}*/
			

		}
		//printf("Max %d : %d\n", k + 1, max);
		printf("%ld\n", max);
		//free(a);
	}

	return 0;

}