#include<stdio.h>
#include<stdlib.h>

const long long row = 100, col = 100;
long long N, q, lastAnswer = 0;
long long i = 0;
long long *counter;

void query1 ( long long *array[q], long long  x, long long y ) {

	long long index = ( x ^ lastAnswer) % N;
	array[index][counter[index]++] = y;
	//printf("%lld. Value of array[%lld][%lld] : %lld\n", ++i, index, counter[index] - 1, array[index][counter[index] - 1] );
}

void query2 ( long long *array[q], long long  x, long long y ) {

	long long index = ( x ^ lastAnswer )  % N;
	long long temp_col = y % counter[index];
	lastAnswer = array[index][temp_col];
	//printf("%lld. Array [%lld][%lld] --> last lastAnswer : %lld\n", ++i, index, temp_col, lastAnswer);
	printf("%lld\n", lastAnswer );
}

int main () {

	long long check_query, x, y;

	scanf("%lld %lld\n", &N, &q);
	long long *array[q];
	for (long long i = 0; i < q; i++) {
		array[i] = (long long *) malloc(N*sizeof(long long));
	}
	counter = (long long *) malloc(100000*sizeof(long long));
	for (long long i = 0; i < N; i++ ){
		counter[i] = 0;
	}

	for (long long i = 0; i < q; i++ ) {
        scanf("%lld %lld %lld\n", &check_query, &x, &y);

        switch (check_query) {

        case 1 :
        	query1 (array, x, y);
        	break;
        case 2 :
        	query2 (array, x, y);
        	break;
        default :
        	printf("Wrong input ! ");
        	return 1;
	    }
	}

	return 0;
}
