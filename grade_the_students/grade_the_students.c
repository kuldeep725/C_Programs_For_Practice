#include<stdio.h>

typedef struct {

	int id;
	char first_name[30];
	char last_name[30];
	float physics;
	float chemistry;
	float maths;
	float average;
	char grade;

} students;

int get_total_students_and_set_data(students *, FILE *);
void set_student_average (students *, int);
float get_student_net_average (students *, int );
void set_grade_students (students *, int , float );
void generate_results (students *, int );


int get_total_students_and_set_data (students *s, FILE *f) {

	int i = 0; 
	printf("Starting\n");

	while(fscanf(f,"%d %s %s %f %f %f",
		&(s[i].id),s[i].first_name,s[i].last_name,&(s[i].physics),
		&(s[i].chemistry),&(s[i].maths)) == 6)
		i++;
	
	return i;
	
}

void set_student_average (students *s,int total) {

	int i;
	for (i = 0; i < total; i++)
		s[i].average = ( s[i].physics + s[i].chemistry + s[i].maths ) / 3;
}

float get_student_net_average (students *s, int total) {

	int i = 0;
	float net_average = 0;
	for(i = 0; i < total; i++) {
		net_average += s[i].average;
	}
	return net_average / i;

}

void set_grade_students (students *s, int total,float net_average) {

	int i;
	for(i = 0; i < total; i++) {
		if (s[i].average < net_average/2) 
			s[i].grade = 'F';
		else if (s[i].average < net_average) 
			s[i].grade = 'C';
		else if (s[i].average == net_average)
			s[i].grade = 'B';
		else if (s[i].average < net_average*2)
			s[i].grade = 'A';
		else 
			s[i].grade = 'S';

	}
}

void generate_results (students *s, int total) {
	printf("\n----------RESULT OF STUDENTS---------- \n\n");
	printf("%-10s%-20s%-20s%-15s%-15s%-15s%-15s%-15s\n\n","ID","FIRST NAME","LAST NAME",
		"PHYSICS","CHEMISTRY","MATHS","AVERAGE","GRADES"
	);
	int i = 0;

	for (i = 0; i < total; i++) {
		printf("%-10d%-20s%-20s%-15.0f%-15.0f%-15.0f%-15.2f%-15c\n",s[i].id,s[i].first_name,
			s[i].last_name,s[i].physics,s[i].chemistry,s[i].maths,s[i].average,
			s[i].grade
		);
	}
}

int TOTAL = 10;

int main() {
	
	students s[TOTAL];

	FILE *f = fopen("data.txt","r");
	if (f == 0) {
		fprintf(stderr, "%s\n","ERROR IN FILE OPENING");
		return 1;
	}

	int total_students = get_total_students_and_set_data(s,f);
	printf("TOTAL STUDENTS : %d\n", total_students);
	set_student_average(s,total_students);
	
	float students_net_average = get_student_net_average(s,total_students);

	printf("CLASS AVERAGE : %.2f\n", students_net_average);
	set_grade_students(s,total_students,students_net_average);

	generate_results(s,total_students);
	return 0;

}
