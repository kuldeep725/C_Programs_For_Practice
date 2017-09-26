#include<stdio.h>


int main() {

    int arr[6][6], counter = 0, sum_arr[16];

    for ( int arr_i = 0; arr_i < 6; arr_i++ ) 
    	for( int arr_j = 0; arr_j < 6; arr_j++ )
        	scanf("%d ",&arr[arr_i][arr_j]);
   
    for ( int i = 0; i < 4; i++ ) {
    	for (int l = 0; l < 4; l++ ) {
    		sum_arr[counter] = 0;
	    	for ( int j = i; j < i+3; j++ ) {
	    		for ( int k = l; k < l+3; k++ ) {
	    			//printf("Checking (j = %d) and (i+1 = %d) and (k = %d) and (l=%d)  \n",j,i+1,k,l );
	    			if ( j == i+1) {
	    				if ( k == l+1) {
	    					//printf("array[%d][%d] : %d\n", j, k, arr[j][k] );
	    					sum_arr[counter] += arr[j][k];
	    				}
	    				else {
	    					//printf("Non-adding array[%d][%d] : %d\n", j, k, arr[j][k] );
	    				}
	    			}
	    			else {
	    				//printf("array[%d][%d] : %d\n", j, k, arr[j][k] );
	    				sum_arr[counter] += arr[j][k];
	    			}
	    		}
	    	}
	    	//printf("Sum of hourglass [%d] : %d\n", counter, sum_arr[counter] );
	    	counter++;
	    }
   }

   int max = sum_arr[0];	//to find maximum hourglass

   for ( int i = 0; i < 16; i++)
   		if (max < sum_arr[i]) 
   			max = sum_arr[i];	
   //printf("Maximum hourglass is : %d\n", max);
   printf("%d", max );
   return 0;

}