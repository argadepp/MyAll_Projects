/*
 * menu.c
 *
 *  Created on: 20-Feb-2018
 *      Author: sunbeam
 */

#include <stdio.h>
#include "menu.h"

enum options menu()
{
	enum options choice;
	printf("\n\n0. exit\n1. factorial\n2. combination\n3. pascal\nenter choice.. ");
	scanf("%d", &choice);
	return choice;
}

