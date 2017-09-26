/*
	Aim : Evaluate postfix expression with single digit operands 
		  and operators only (+, -, /, *)
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 30

struct stack
{
	int a[size];
	int top;		
} s ;


void push ( int newElement ) {

	if ( s.top == size -1 ) 
		printf("Size Overflow\n");

	else {
		s.a[s.top++] = newElement;
		//printf("New Element number (%d) %d is added.\n", newElement, s.top);
	}

}

int pop () {

	if ( s.top == 0 ) {
		printf("Size Underflow\n");
		return 1;
	}

	else
		return s.a[--s.top];
}

int evaluate_expression ( int a, int b, char ch) {

	switch (ch) {

		case '+' : return (a+b);
		case '-' : return (a-b);
		case '*' : return (a*b);
		case '/' : return (a/b);

	}
	printf("Operator '%c' is not a proper operator.\n", ch);
	return -1;

}

int evaluate_postfix ( char *expression ) {

	int i = 0;
	int op1;
	int op2;
	int value = -1;
	char ch;

	while ( (ch = expression[i]) != '\0' ) {

		if ( ch >= '0' && ch <= '9' ) {
			push(ch - 48);
			//printf("Character '%c' has value : %d\n", ch, ch);
		}

		else {

			op2 = pop();
			op1 = pop();
			value = evaluate_expression(op1, op2, ch);
			//printf("op1 : %d, op2 : %d, ch : %c, value : %d\n", op1, op2, ch, value);
			push (value);

		}
		i++;

	}

	return value;

}

int main () {

	char postFix[30];
	s.top = 0;
	//printf("top = %d\n", s.top);
	scanf("%s", postFix);
	printf("The answer of expression (\"%s\") is : %d.x\n", postFix, evaluate_postfix(postFix));
	if ( evaluate_postfix(postFix) == -1 ) {
		puts ("The answer evaluated is wrong since postfix expression is not proper");
		return 1;
	}
	return 0;

}