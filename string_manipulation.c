#include<stdio.h>

int main() {
	char name[40],your[49];
	int ch,chr;
	scanf("%[^\n]s",name);
	while ((ch = getchar()) != '\n' && ch != EOF);
	scanf("%[^\n]s",your);
	while ((chr = getchar()) != '\n' && chr != EOF);
	//scanf("%40[^\n]s",name);
	//scanf("%40[^\n]s",your);
	printf("%s\n%s\n",name,your);
	return 0;
}