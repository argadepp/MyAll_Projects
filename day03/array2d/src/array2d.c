/*
 ============================================================================
 Name        : array2d.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

enum dirn
{
	LEFT, RIGHT, UP, DOWN
};

void print(int a[][4], int rows, int cols);
void print_spiral(int a[][5], int n);
int main(void)
{
	int arr[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int mat[5][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	//print(arr, 3, 4);
	print_spiral(mat, 5);
	return 0;
}

void print(int a[][4], int rows, int cols)
{
	int i, j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}

void print_spiral(int a[][5], int n)
{
	int t=1, r=0, c=0, min=0, max=n-1;
	enum dirn dir = RIGHT;
	for(t=1; t<=25; t++)
	{
		printf("%d, ", a[r][c]);
		switch(dir)
		{
		case LEFT:
			if(c > min)
				c--;
			else
			{
				dir = UP;
				r--;
				min++;
			}
			break;
		case RIGHT:
			if(c < max)
				c++;
			else
			{
				dir = DOWN;
				r++;
			}
			break;
		case UP:
			if(r > min)
				r--;
			else
			{
				max--;
				c++;
				dir = RIGHT;
			}
			break;
		case DOWN:
			if(r < max)
				r++;
			else
			{
				dir = LEFT;
				c--;
			}
			break;
		}
	}
}

