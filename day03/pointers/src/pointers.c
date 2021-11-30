/*
 ============================================================================
 Name        : pointers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 10;
	int *p;
	int **pp;
	p = &a;
	pp = &p;
	printf("&a = %p\n", &a);
	printf("&p = %p\n", &p);
	printf("p = %p\n", p);
	printf("*p = %d\n", *p);
	printf("&pp = %p\n", &pp);
	printf("pp = %p\n", pp);
	printf("*pp = %p\n", *pp);
	printf("**pp = %d\n", **pp);

	printf("sizeof(p) = %u\n", sizeof(p));
	printf("sizeof(pp) = %u\n", sizeof(pp));
	return 0;
}

/*
64-bit compilation:
	gcc -c pointers.c
	gcc -o pointers pointer.o

32-bit compilation:
	gcc -m32 -c pointers.c
	gcc -m32 -o pointers pointer.o

64-bit compilation in eclipse:
	default project settings.

32-bit compilation in eclipse:
	Project -> Properties -> C/C++ Build -> Settings
		GCC C Compiler -> Miscelleneous -> -m32
		GCC C Linker -> Miscelleneous -> -m32
*/







