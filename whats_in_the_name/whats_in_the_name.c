#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int getNumberOfSpaces ( char *name ) {

	int count = 0;
	int i;
	//printf("name = %s", name);
	for (i = 0; i < strlen(name); ++i)	
	{
		if (name[i] == ' ') 
			count++;
	}
	return count;
}

void formatNameZeroSpace (char *inputName, char *outputName) {

	int i;
	for (i = 0; i < strlen(inputName); ++i)
	{	
		if (i == 0)
			outputName[0] = toupper(inputName[i]);
		else 
			outputName[i] = tolower(inputName[i]);
	}
	outputName[i] = '\0';

}

void formatNameOneSpace (char *inputName, char *outputName) {

	int count = 0;
	int outputCount = 0;
	int i;
	for (i = 0; i < strlen(inputName); ++i)
	{	
		if (i == 0){
			outputName[outputCount++] = toupper(inputName[i]);
			outputName[outputCount++] = '.';
		}

		if (inputName[i] == ' ') {
			count++;
		}

		if (count == 1) {
			if (inputName[i-1] == ' ')
				outputName[outputCount++] = toupper(inputName[i]);
			else
				outputName[outputCount++] = tolower(inputName[i]);
		}
	}
	outputName[outputCount++] = '\0';

}

void formatNameTwoSpace (char *inputName, char *outputName) {

	int count = 0;
	int outputCount = 0;
	int i;

	for (i = 0; i < strlen(inputName); ++i)
	{
		if (i == 0){
			outputName[outputCount++] = toupper(inputName[i]);
			outputName[outputCount++] = '.';
		}

		if (inputName[i] == ' ') {
			count++;
		}

		if (count == 1 && inputName[i-1] == ' ') {
			outputName[outputCount++] = ' ';
			outputName[outputCount++] = toupper(inputName[i]);
			outputName[outputCount++] = '.';
		}

		if (count == 2) {
			if (inputName[i-1] == ' ')
				outputName[outputCount++] = toupper(inputName[i]);
			else
				outputName[outputCount++] = tolower(inputName[i]);
		}
	}
	outputName[outputCount++] = '\0';

}

int main () {

	int t;
	scanf("%d\n", &t);
	int i;

	char name[100][40];					//input name 2-D array
	char formatted_name[100][40];		//output name 2-D array	
	int count_spaces;					//count spaces

	for (i = 0; i < t; i++) {

		fgets(name[i], sizeof(name[i]), stdin);

	}

	for (i = 0; i < t; ++i)
	{
		count_spaces = getNumberOfSpaces(name[i]);
		//printf("spaces of %d : '%d'\n", i+1, count_spaces);

		switch (count_spaces) {

			case 0 :
				formatNameZeroSpace(name[i], formatted_name[i]);
				break;

			case 1 :
				formatNameOneSpace(name[i], formatted_name[i]);
				break;

			case 2 :
				formatNameTwoSpace(name[i], formatted_name[i]);
				break;

			default :
				printf("Wrong Counting !!\n");
				break;

		}
	}

	for (i = 0; i < t; i++) {

		printf("%s", formatted_name[i]);

	}
	printf("\n");

	return 0;
}