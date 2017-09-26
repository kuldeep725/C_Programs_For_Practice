#include<stdio.h>
#include<string.h>

typedef struct name {

	int age;
	char name[40];
	
} students;

void set_students (students *);
void read_file (FILE *,students *);
void show_file (FILE *,students *); 

int main() {

	students s[50];
	set_students(s);
	printf("Name : %s\nAge : %d\n",s[0].name, s[0].age);
	FILE *f = fopen("tempFile.txt","w");
	read_file(f,s);
	show_file(f,s);
	
	fclose(f);

}

void set_students (students *s) {

	int i; 
	s[1].age = 5;
	strcpy(s[1].name,"Hello");
	//printf("Name : %s\nAge : %d\n",s[0].name, s[0].age);

}
void read_file (FILE *f,students *s) {

	fprintf(f, "Name : %s\nAge : %d\n",s[1].name, s[1].age);

} 
void show_file (FILE *f,students *s) {
	printf("New Name : %s\nNew Age : %d\n",s[1].name, s[1].age );
}