#include<stdio.h>

int main() {

	float latitude, longitude;
	char info[50];

	while (scanf("%f, %f, %50[^\n]",&latitude,&longitude,info) == 3) {

		if (latitude <  34 && latitude > 26) {
			if (longitude < -64 && longitude > -76)
				printf("%f, %f, %s\n", latitude, longitude, info);
			else 
				fprintf(stderr, "Invalid longitude : %f\n",longitude );
		}
		else
			fprintf(stderr, "Invalid latitude : %f\n",latitude );

	}
	return 0;
}