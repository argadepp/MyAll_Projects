/*
 ============================================================================
 Name        : dma2d.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int** alloc_matrix(int rows, int cols)
{
	int i, **mat = (int**)malloc(rows * sizeof(int*));
	for(i=0; i<rows; i++)
		mat[i] = (int*) malloc(cols * sizeof(int));
	return mat;
}
void free_matrix(int **mat, int rows)
{
	int i;
	for(i=0; i<rows; i++)
		free(mat[i]);
	free(mat);
}
void input_matrix(int **mat, int rows, int cols)
{
	int i, j;
	printf("enter matrix (%d x %d) : \n", rows, cols);
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			scanf("%d", &mat[i][j]);
	}
}
void print_matrix(int **mat, int rows, int cols)
{
	int i, j;
	printf("matrix (%d x %d) : \n", rows, cols);
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
}
int** matrix_multiply(int **mat1, int rows1, int cols1, int **mat2, int rows2, int cols2)
{
	if(cols1 != rows2)
		return NULL;
	int i, j, k, sum, **resmat = alloc_matrix(rows1, cols2);

	for(i=0; i<rows1; i++)
	{
		for(j=0; j<cols2; j++)
		{
			sum = 0;
			for(k=0; k<rows2; k++)
				sum += mat1[i][k] * mat2[k][j];
			resmat[i][j] = sum;
		}
	}
	return resmat;
}

int main(void)
{
	int **mat1, **mat2, **mat3;
	mat1 = alloc_matrix(3, 3);
	mat2 = alloc_matrix(3, 3);
	input_matrix(mat1, 3, 3);
	input_matrix(mat2, 3, 3);
	mat3 = matrix_multiply(mat1, 3, 3, mat2, 3, 3);
	print_matrix(mat3, 3, 3);
	free_matrix(mat1, 3);
	free_matrix(mat2, 3);
	free_matrix(mat3, 3);
	return 0;
}

