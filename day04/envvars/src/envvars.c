/*
 ============================================================================
 Name        : envvars.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[])
{
	int i;
	for(i=0; envp[i]!=NULL; i++)
		puts(envp[i]);
	return 0;
}

