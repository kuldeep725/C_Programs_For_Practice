#include<stdio.h>

void  calling_function () {
	i = 4;
	printf("%d\n", i );
}

int main () {

	static int i = 0;
	printf("main i = %d", i);
	calling_function();
	return 0;

}