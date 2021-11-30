#include <stdio.h>
/*
 * struct_book.c
 *
 *  Created on: 23-Feb-2018
 *      Author: sunbeam
 */
/*
struct date
{
	int day, month, year;
};

struct book
{
	int id;
	char name[20];
	double price;
	struct date publish;
};
*/

struct book
{
	int id;
	char name[20];
	double price;
	struct date
	{
		int day, month, year;
	} publish;
};

void input_book(struct book *p);
void print_book(struct book b);
void input_books(struct book a[], int n);
void print_books(struct book a[], int n);

int main()
{
	struct book b1;
	struct book arr[3];
	//input_book(&b1);
	//print_book(b1);
	input_books(arr, 3);
	print_books(arr, 3);
	return 0;
}

void input_book(struct book *p)
{
	printf("Enter Book Details: id, name, price, publish:day,month,year : ");
	scanf("%d%s%lf%d%d%d", &p->id, p->name,&p->price,
			&p->publish.day, &p->publish.month, &p->publish.year);
}

void print_book(struct book b)
{
	printf("BOOK: %d, %s, %.2lf, %d-%d-%d\n", b.id, b.name, b.price,
			b.publish.day, b.publish.month, b.publish.year);
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
	for(i=0; i<n; i++)
		printf("BOOK: %d, %s, %.2lf, %d-%d-%d\n", a[i].id, a[i].name, a[i].price,
				a[i].publish.day, a[i].publish.month, a[i].publish.year);
}


