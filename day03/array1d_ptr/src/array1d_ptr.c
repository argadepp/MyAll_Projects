/*
 ============================================================================
 Name        : array1d_ptr.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void print(int a[]);

int main(void)
{
	int i, arr[5] = {11, 22, 33, 44};
	int *ptr;

	ptr = arr; //ptr = &arr[0];

	printf("arr[i]\t\t: ");
	for(i=0; i<5; i++)
		printf("%d, ", arr[i]);
	printf("\n");

	printf("*(arr+i)\t: ");
	for(i=0; i<5; i++)
		printf("%d, ", *(arr+i));
	printf("\n");

	printf("*(i+arr)\t: ");
	for(i=0; i<5; i++)
		printf("%d, ", *(i+arr));
	printf("\n");

	printf("i[arr]\t\t: ");
	for(i=0; i<5; i++)
		printf("%d, ", i[arr]);
	printf("\n");

	printf("ptr[i]\t\t: ");
	for(i=0; i<5; i++)
		printf("%d, ", ptr[i]);
	printf("\n");

	printf("*(ptr+i)\t: ");
	for(i=0; i<5; i++)
		printf("%d, ", *(ptr+i));
	printf("\n");

	printf("*(i+ptr)\t: ");
	for(i=0; i<5; i++)
		printf("%d, ", *(i+ptr));
	printf("\n");

	printf("i[ptr]\t\t: ");
	for(i=0; i<5; i++)
		printf("%d, ", i[ptr]);
	printf("\n");

	printf("sizeof(arr) : %d\n", sizeof(arr));
	printf("sizeof(ptr) : %d\n", sizeof(ptr));
	ptr++;
	//arr++; // error: arr is not a pointer

	print(arr);
	return 0;
}

void print(int a[])
//void print(int *a)
{
	printf("sizeof(a) : %d\n", sizeof(a));
}


