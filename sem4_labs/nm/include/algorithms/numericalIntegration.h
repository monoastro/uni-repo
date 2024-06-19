#pragma once
#include "definitions.h"

void trapezoidal()
{
	printf("Trapezoidal Rule\n");
	double a, b, n, h, sum = 0;
	printf("Enter the limits of integration:\n");
	scanf("%lf %lf", &a, &b);
	printf("Enter the number of subintervals:\n");
	scanf("%lf", &n);
	h = (b - a) / n;
	for (unsigned i = 1; i < n; i++)
	{
		sum += 2 * fn7_1(a + i * h);
	}
	sum += (fn7_1(a) + fn7_1(b));
	sum *= h / 2;
	printf("The integral of the function is %10.6lf.\n", sum);
}

double trapezoidal(double a, double b, double h)
{
	double sum = 0;
	unsigned n = (b - a) / h;
	for (unsigned i = 1; i < n; i++)
	{
		sum += 2 * fn7_2(a + i * h);
	}
	sum += (fn7_2(a) + fn7_2(b));
	sum *= h / 2;
	return sum;
}

void rombergsMethod()
{
	printf("Romberg's Method\n");
	double a, b, h;
	unsigned numHalves;
	printf("Enter the limits of integration:\n");
	scanf("%lf %lf", &a, &b);
	printf("Enter the initial size of the subintervals:\n"); 
	scanf("%lf", &h);
	printf("Enter the number of times to apply the scheme:\n");
	scanf("%u", &numHalves);

	//i'm storing the values of romberg's binary tree in a matrix 
	double **matrix;
	matrix = (double**)malloc(sizeof(double*) * (numHalves + 1));
	for (unsigned i = 0; i < numHalves + 1; i++) matrix[i] = (double*)malloc(sizeof(double) * (numHalves + 1 - i));

	for (unsigned i = 0; i < numHalves + 1; i++)
	{
		matrix[i][0] = trapezoidal(a, b, h);
		h /= 2;
	}
	
	//filling in the rest of the matrix using the scheme
	for(unsigned j = 1; j < numHalves + 1; j++)
	{
		for(unsigned i = 0; i < numHalves + 1 - j; i++)
		{
			matrix[i][j] = 1/3.0 * (4 * matrix[i + 1][j - 1] - matrix[i][j - 1]);
		}
	}

	//print the matrix to see what it looks like
	for (unsigned i = 0; i < numHalves + 1; i++)
	{
		for (unsigned j = 0; j < numHalves + 1 - i; j++)
		{
			printf("%10.6lf ", matrix[i][j]);
		}
		printf("\n");
	}
	
	for (unsigned i = 0; i < numHalves + 1; i++) free(matrix[i]);
	free(matrix);
}

void simpsonsOneThird()
{
	printf("Simpson's 1/3 Rule\n");
	double a, b, n, h, sum = 0;
	printf("Enter the limits of integration:\n");
	scanf("%lf %lf", &a, &b);
	printf("Enter the number of subintervals:\n");
	scanf("%lf", &n);
	h = (b - a) / n;
	for (unsigned i = 1; i < n; i++)
	{
		if (i % 2 == 0)
		{
			sum += 2 * fn7_1(a + i * h);
		}
		else
		{
			sum += 4 * fn7_1(a + i * h);
		}
	}
	sum += fn7_1(a) + fn7_1(b);
	sum *= h / 3;
	printf("The integral of the function is %10.6lf.\n", sum);
}

void simpsonsThreeEighths()
{
	printf("Simpson's 3/8 Rule\n");
	double a, b, n, h, sum = 0;
	printf("Enter the limits of integration:\n");
	scanf("%lf %lf", &a, &b);
	printf("Enter the number of subintervals:\n");
	scanf("%lf", &n);
	h = (b - a) / n;
	for (unsigned i = 1; i < n; i++)
	{
		if (i % 3 == 0)
		{
			sum += 2 * fn7_1(a + i * h);
		}
		else
		{
			sum += 3 * fn7_1(a + i * h);
		}
	}
	sum += fn7_1(a) + fn7_1(b);
	sum *= 3 * h / 8;
	printf("The integral of the function is %10.6lf.\n", sum);
}

