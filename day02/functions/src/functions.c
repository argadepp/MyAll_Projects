#include <stdio.h>
#include <stdlib.h>

// menu-driven programming
/*
// symbolic constants --> can be any data type const (int/double/char/string)
#define PI 3.1415
// replaced by preprocessor
#define EXIT			0
#define FACTORIAL 		1
#define COMBINATION 	2
#define PASCAL_TRI		3
*/

// enum constants --> internally they are ints
// replaced by the compiler
enum options
{
	EXIT, FACTORIAL, COMBINATION, PASCAL_TRI
};

// first enum const value is 0, each enum const value is value of prev const + 1.
// enum const values can be assigned, can be -ve, can be duplicated.
enum color
{
	RED=-2, GREEN, BLUE, BLACK=0, BROWN, YELLOW
};
// red=-1, green=-1, blue=0, black=0, brown=1, yellow=2
// enum is user defined data type -- internally mapped to int data-type.
// size of enum type is same as int i.e. 4 bytes.
// enum is for making program readable.

// keywords --> C programming --> standards :: C89 = 32, C99 = ??
// ritchie = 27 keywords
// ANSI C = 5 keywords = void, enum, const, volatile, signed

int fact(int n);
int combn(int n, int r);
void pascal(int max);
enum options menu();

int main(void)
{
	int res, n, r;
	enum options choice;
	printf("size of enum : %u\n", sizeof(choice));
	do
	{
		choice = menu();
		switch(choice)
		{
		case FACTORIAL: // factorial
			printf("enter a number : ");
			scanf("%d", &n);
			res = fact(n);
			printf("factorial : %d\n", res);
			break;
		case COMBINATION: // combination
			printf("enter two number (n,r) : ");
			scanf("%d%d", &n, &r);
			res = combn(n, r);
			printf("combination : %d\n", res);
			break;
		case PASCAL_TRI: // pascal triangle
			printf("enter number of lines : ");
			scanf("%d", &n);
			pascal(n);
			break;
		}
	}while(choice != EXIT);
	return 0;
}

int fact(int n)
{
	int r = 1;
	while(n > 0)
		r = r * n--;
	return r;
}

//nCr = n! / (r! * (n-r)!)
int combn(int n, int r)
{
	int res;
	res = fact(n) / (fact(r) * fact(n-r));
	return res;
}

void pascal(int max)
{
	int n, r, s, ncr;
	for(n=0; n<max; n++)
	{
		for(s=1; s<max-n; s++)
			printf("\t");
		for(r=0; r<=n; r++)
		{
			ncr = combn(n, r);
			printf("%d\t\t", ncr);
		}
		printf("\n");
	}
}

enum options menu()
{
	enum options choice;
	printf("\n\n0. exit\n1. factorial\n2. combination\n3. pascal\nenter choice.. ");
	scanf("%d", &choice);
	return choice;
}

