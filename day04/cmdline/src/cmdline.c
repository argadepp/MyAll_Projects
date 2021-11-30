/*
 ============================================================================
 Name        : cmdline.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
//int main(int argc, char **argv)
{
	int i;
	for(i=0; i<argc; i++)
		puts(argv[i]);
	return 0;
}
