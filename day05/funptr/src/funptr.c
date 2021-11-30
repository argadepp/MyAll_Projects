/*
 ============================================================================
 Name        : funptr.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void add(int a, int b)
{
	int c = a + b;
	printf("add : %d\n", c);
}

void subtract(int a, int b)
{
	int c = a - b;
	printf("subtract : %d\n", c);
}

void mutliply(int a, int b)
{
	int c = a * b;
	printf("multiply : %d\n", c);
}

struct arithmetic {
   void (*m_add)(int, int);
   void (*m_subtract)(int, int);
   void (*m_multiply)(int, int);
};

void calc( void (*op)(int,int), int a, int b)
{
    op(a,b);
}

int main(void)
{
	void (*ptr)(int,int); // declaration of function pointer
	printf("\n calling function ...\n");
	add(23, 5); // early binding
		// push 5
		// push 23
		// call 0x21873624 ; add=0x21873624
		// pop
		// pop
	printf("\n using function pointer ...\n");
	ptr = add; // initialization of function pointer
	ptr(23, 5); // function call using pointer // late binding
		// push 5
		// push 23
		// call [ptr]
		// pop
		// pop

	printf("\n array of function pointer ...\n");
	void (*arr[3])(int,int);
	int i;
	arr[0] = add;
	arr[1] = subtract;
	arr[2] = mutliply;
	for(i=0; i<3; i++)
		arr[i](23, 5);

	printf("\n struct member - function pointer ...\n");
	struct arithmetic ar;
	ar.m_add = add;
	ar.m_subtract = subtract;
	ar.m_multiply = mutliply;

	ar.m_add(23, 5);
	ar.m_subtract(23, 5);
	ar.m_multiply(23, 5);

	printf("\n function arg - function pointer ...\n");
    calc(add, 23, 5);
    calc(subtract, 23, 5);
    calc(mutliply, 23, 5);

    return 0;
}
