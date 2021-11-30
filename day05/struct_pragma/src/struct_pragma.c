/*
 ============================================================================
 Name        : struct_pragma.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

struct test
{
	int a;
	char b;
	int c;
	char d;
};

int main(void)
{
	struct test t1;
	printf("size : %u\n", sizeof(struct test));
	printf("&t1 : %u\n", &t1);
	printf("&t1.a : %u\n", &t1.a);
	printf("&t1.b : %u\n", &t1.b);
	printf("&t1.c : %u\n", &t1.c);
	printf("&t1.d : %u\n", &t1.d);
	return 0;
}


