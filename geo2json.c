#include<stdio.h>

int main () {

	char info[50];
	float latitude, longitude;
	puts("data=[");
	while (scanf("%f, %f, %50[^\n]",&latitude,&longitude,info) == 3) {

		if (latitude > 90 || latitude < -90 ) {
			fprintf(stderr, "Invalid latitude : %f\n",latitude );
			continue;
		}
		if (longitude > 180 || longitude < -180 ) {
			fprintf(stderr, "Invalid longitude : %f\n",longitude );
			continue;
		}

		printf("\t{ latitude = %f, longitude = %f, info = %s },\n",latitude,longitude,info);

	}
	puts("]");
	return 0;

}