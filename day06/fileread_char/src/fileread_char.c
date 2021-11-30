/*
 ============================================================================
 Name        : fileread_char.c
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
	FILE *fp;
	int ch;
	fp = fopen("/home/sunbeam/feb18/dac/c/readme.txt", "r");
	if(fp == NULL)
	{
		perror("fopen() failed");
		exit(1);
	}
	while( (ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
	}
	fclose(fp);
	return 0;
}



