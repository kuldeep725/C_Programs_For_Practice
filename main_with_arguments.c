#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	
	int count = 0, check_launched = 0;
	char *launch_rocket = "";
	char ch, *message;

	while ((ch = getopt(argc, argv, "lc:")) != EOF) {
		switch (ch) {

			case 'c' :
				launch_rocket =  optarg;
				break;
			case 'l' : 
				check_launched = 1;
				break;
			default : 
				fprintf(stderr, "%s%s\n", "UNKNOWN OPTION : ",optarg);
				return 1;

		}
	}
	argv += optind;
	argc -= optind;

	if (check_launched) 
		puts("Launch the rocket!");
	if (launch_rocket[0]) 
		printf("Rock the mission, %s !\n",launch_rocket);

	puts("\nLIST OF PLANETS :");

	for (count = 0; count < argc; count++) 
		puts(argv[count]);
	
	return 0;

}