/*
 ============================================================================
 Name        : filewr_printf.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct book
{
	int id;
	char name[20];
	double price;
	struct date
	{
		int day, month, year;
	} publish;
} book_t;

void input_books(struct book a[], int n);
void print_books(struct book a[], int n);
void print_stock_report(struct book a[], int n);

int main(void)
{
	book_t arr[3] =
	{
		{101, "Let Us C", 234.56, {1, 1, 2000} },
		{102, "Pointers in C", 523.42, {3, 1, 2005} },
		{103, "ANSI C Programming", 140.34, {8, 9, 2003} },
	};
	print_books(arr, 3);
	print_stock_report(arr, 3);
	return 0;
}


void input_books(struct book a[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("Enter Book Details: id, name, price, publish:day,month,year : ");
		scanf("%d%s%lf%d%d%d", &a[i].id, a[i].name,&a[i].price,
				&a[i].publish.day, &a[i].publish.month, &a[i].publish.year);
	}
}

void print_books(struct book a[], int n)
{
	int i;
	printf("|%-4s|%-20s|%-8s| %-10s |\n", "ID", "NAME", "PRICE", "PUBLISH");
	printf("------------------------------------------------\n");
	for(i=0; i<n; i++)
	{
		printf("|%4d|%-20s|%8.2lf| %02d-%02d-%04d |\n", a[i].id, a[i].name, a[i].price,
				a[i].publish.day, a[i].publish.month, a[i].publish.year);
	}
	printf("------------------------------------------------\n");
}

void print_stock_report(struct book a[], int n)
{
	int i;
	FILE *fp = fopen("report.txt", "w");
	if(fp == NULL)
	{
		perror("fopen() failed");
		exit(1);
	}
	fprintf(fp, "|%-4s|%-20s|%-8s| %-10s |\n", "ID", "NAME", "PRICE", "PUBLISH");
	fprintf(fp, "------------------------------------------------\n");
	for(i=0; i<n; i++)
	{
		fprintf(fp, "|%4d|%-20s|%8.2lf| %02d-%02d-%04d |\n", a[i].id, a[i].name, a[i].price,
				a[i].publish.day, a[i].publish.month, a[i].publish.year);
	}
	fprintf(fp, "------------------------------------------------\n");
	fclose(fp);
}
