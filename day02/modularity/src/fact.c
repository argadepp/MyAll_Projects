/*
 * fact.c
 *
 *  Created on: 20-Feb-2018
 *      Author: sunbeam
 */

#include <stdio.h>
#include "fact.h"

int fact(int n)
{
	int r = 1;
	while(n > 0)
		r = r * n--;
	return r;
}

//nCr = n! / (r! * (n-r)!)
int combn(int n, int r)
{
	int res;
	res = fact(n) / (fact(r) * fact(n-r));
	return res;
}

void pascal(int max)
{
	int n, r, s, ncr;
	for(n=0; n<max; n++)
	{
		for(s=1; s<max-n; s++)
			printf("\t");
		for(r=0; r<=n; r++)
		{
			ncr = combn(n, r);
			printf("%d\t\t", ncr);
		}
		printf("\n");
	}
}

