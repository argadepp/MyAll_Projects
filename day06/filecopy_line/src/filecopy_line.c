/*
 ============================================================================
 Name        : filecopy_line.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// ./filecopy_line <srcfile> <destfile>
// argv[0]		  argv[1]	argv[2]
int main(int argc, char* argv[])
{
	FILE *fs, *fd;
	int cnt;
	char line[512];

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

	cnt=0;
	while( fgets(line, sizeof(line), fs) != NULL )
	{
		fputs(line, fd);
		cnt++;
	}

	fclose(fd);
	fclose(fs);

	printf("Number of lines copied : %d\n", cnt);
	return 0;
}
