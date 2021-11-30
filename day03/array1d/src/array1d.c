/*
 ============================================================================
 Name        : array1d.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

float calc_avg(float m[]);

int main()
{
    float marks[SIZE], avg;
    int i;
    printf("enter marks of %d subjects : ", SIZE);
    for(i=0; i<SIZE; i++)
        scanf("%f", &marks[i]);
    avg = calc_avg(marks);
    printf("avg: %f\n", avg);
    return 0;
}

float calc_avg(float m[])
{
	float avg, total = 0.0f;
	int i;
    for(i=0; i<SIZE; i++)
        total += m[i];
    avg = total / SIZE;
    return avg;
}
