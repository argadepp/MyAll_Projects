#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "fact.h"
 

int main(void)
{
	int res, n, r;
	enum options choice;

	do
	{
		choice = menu();
		switch(choice)
		{
		case FACTORIAL: // factorial
			printf("enter a number : ");
			scanf("%d", &n);
			res = fact(n);
			printf("factorial : %d\n", res);
			break;
		case COMBINATION: // combination
			printf("enter two number (n,r) : ");
			scanf("%d%d", &n, &r);
			res = combn(n, r);
			printf("combination : %d\n", res);
			break;
		case PASCAL_TRI: // pascal triangle
			printf("enter number of lines : ");
			scanf("%d", &n);
			pascal(n);
			break;
		}
	}while(choice != EXIT);
	return 0;
}
