/*
 ============================================================================
 Name        : filecopy_ch.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// ./filecopy_ch <srcfile> <destfile>
// argv[0]		  argv[1]	argv[2]
int main(int argc, char* argv[])
{
	FILE *fs, *fd;
	int ch, cnt;

	if(argc!=3)
	{
		printf("SYNTAX: ./filecopy_ch <srcfile> <destfile>\n");
		exit(1);
	}

	fs = fopen(argv[1], "r");
	if(fs == NULL)
	{
		perror("fopen() failed for source file");
		exit(2);
	}

	fd = fopen(argv[2], "w");
	if(fd == NULL)
	{
		perror("fopen() failed for dest file");
		fclose(fs);
		exit(2);
	}

	cnt = 0;
	while( (ch = fgetc(fs)) != EOF )
	{
		fputc(ch, fd);
		cnt++;
	}

	fclose(fd);
	fclose(fs);

	printf("Number of bytes copied : %d\n", cnt);
	return 0;
}
