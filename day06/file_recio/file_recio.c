/*
 * file_recio.c
 *
 *  Created on: 24-Feb-2018
 *      Author: sunbeam
 */
#include <stdio.h>
#include <stdlib.h>

#define DB_FILE "books.txt"

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

void input_book(struct book *p);
void print_book(struct book b);
void add_record();
void display_records();
void search_record();
void edit_record();

int main()
{
	//add_record();
	display_records();
	//search_record();
	//edit_record();
	return 0;
}

void add_record()
{
	book_t b;
	FILE *fp;
	input_book(&b);
	fp = fopen(DB_FILE, "ab");
	if(fp == NULL)
	{
		perror("fopen() failed");
		exit(1);
	}
	fwrite(&b, sizeof(book_t), 1, fp);
	fclose(fp);
}

void display_records()
{
	FILE *fp;
	book_t b;

	fp = fopen(DB_FILE, "rb");
	if(fp == NULL)
	{
		perror("fopen() failed");
		exit(1);
	}

	while(fread(&b, sizeof(book_t), 1, fp) > 0)
	{
		print_book(b);
	}
	fclose(fp);
}

void search_record()
{
	FILE *fp;
	book_t b;
	int id, found=0;
	printf("enter book id to be searched : ");
	scanf("%d", &id);

	fp = fopen(DB_FILE, "rb");
	if(fp == NULL)
	{
		perror("fopen() failed");
		exit(1);
	}

	while(fread(&b, sizeof(book_t), 1, fp) > 0)
	{
		if(id == b.id)
		{
			print_book(b);
			found = 1;
			break;
		}
	}
	if(found==0)
		printf("record not found.\n");
	fclose(fp);
}

void edit_record()
{
	FILE *fp;
	book_t b;
	int id, found=0;
	long size = sizeof(book_t);
	printf("enter book id to be edited : ");
	scanf("%d", &id);

	fp = fopen(DB_FILE, "rb+");
	if(fp == NULL)
	{
		perror("fopen() failed");
		exit(1);
	}

	while(fread(&b, sizeof(book_t), 1, fp) > 0)
	{
		if(id == b.id)
		{
			print_book(b);
			found = 1;
			// take cur pos behind by 1 record size (48 bytes);
			fseek(fp, -size, SEEK_CUR);
			printf("enter modified record ...\n");
			input_book(&b);
			fwrite(&b, sizeof(book_t), 1, fp);
			break;
		}
	}
	if(found==0)
		printf("record not found.\n");
	fclose(fp);
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
