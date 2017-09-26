#include<stdio.h>

int main() {
	double marks[50],average=0;
	int i=0;
	FILE *f;
	f=fopen("matrix1.txt","r");
	if (f == 0) {
		printf("%s\n","Error in file opening" );
		return 1;
	}
	int suc;
	while(i<200) {
		suc=fscanf(f,"%lf\n",&marks[i++]);
		if(suc == -1) {
			break;
		}
	}

	fclose(f);
	int total_students=i;
	for(i=0; i<total_students; i++) {
		printf("%.2lf\t",marks[i]);
		average += marks[i];
		if(i % 5 == 0) {
			printf("\n");
		}
	}
	average /= total_students;
	printf("\nAverage = %.2lf\n",average);
	return 0;

}