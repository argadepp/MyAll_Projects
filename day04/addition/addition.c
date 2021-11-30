/*
 * addition.c
 *
 *  Created on: 22-Feb-2018
 *      Author: sunbeam
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i, sum = 0, num;
	for(i=1; i<argc; i++)
	{
		num = atoi(argv[i]);
		sum += num;
	}
	printf("result : %d\n", sum);
	return 0;
}




