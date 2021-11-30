/*
 ============================================================================
 Name        : dma1d.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float calc_avg(float m[],int SIZE);

int main()
{
    int SIZE;
	float *marks, avg;
    int i;
    printf("enter number of subjects : ");
    scanf("%d", &SIZE);
    marks = (float*)malloc(SIZE * sizeof(float));
    printf("enter marks of %d subjects : ", SIZE);
    for(i=0; i<SIZE; i++)
        scanf("%f", &marks[i]);
    avg = calc_avg(marks, SIZE);
    printf("avg: %f\n", avg);
    free(marks);
    marks = NULL;
    return 0;
}

float calc_avg(float m[], int SIZE)
{
	float avg, total = 0.0f;
	int i;
    for(i=0; i<SIZE; i++)
        total += m[i];
    avg = total / SIZE;
    return avg;
}

