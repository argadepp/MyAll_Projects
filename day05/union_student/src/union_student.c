/*
 ============================================================================
 Name        : union_student.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct student
{
   int roll;
   int std;
   union result
   {
       char grade;
       float marks;
   } res;
};

void input_stud(struct student *s)
{
	printf("enter roll & std: ");
	scanf("%d%d", &s->roll, &s->std);
	getchar(); //scan \n from input buffer and discard that.
	if(s->std > 4)
	{
		printf("enter marks : ");
		scanf("%f", &s->res.marks);
	}
	else
	{
		printf("enter grade : ");
		scanf("%c", &s->res.grade);
	}
}

void print_stud(struct student *s)
{
	printf("roll: %d, std: %d, ", s->roll, s->std);
	if(s->std > 4)
		printf("marks : %.2f\n", s->res.marks);
	else
		printf("grade : %c\n", s->res.grade);
}

int main(void)
{
	struct student s1;
	input_stud(&s1);
	print_stud(&s1);
	return 0;
}


