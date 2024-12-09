#pragma once
#include "definitions.h"
#define ZERO 1e-6


void gaussElimination()
{
	unsigned size_m, size_n;
	double **matrix, *solution;
	
	printf("Enter the size of the augumented matrix [A:C]; row, column :\n");
	scanf("%u %u", &size_m, &size_n);

	//allocate memory for the row
	matrix = (double**)malloc(size_m*sizeof(double*));
	solution = (double*)malloc(size_m*sizeof(double));
	solution[size_m - 1] = {0};
	//allocate memory for the remaining elements
	for(size_t i = 0; i<size_m; i++) matrix[i] = (double*)malloc(size_n*sizeof(double));

	//initialize the matrix
	//Q_singleSoln(matrix);
	//Q_infiniteSoln1(matrix);
	//Q_infiniteSoln2(matrix);
	//Q_noSoln(matrix);
	//printMatrix(matrix, size_m, size_n);
	//printf("\n");
	
	printf("Enter values of the matrix in order\n");

	//read values from user
	for(size_t i = 0; i<size_m; i++)
	{
		for(size_t j = 0; j<size_n; j++)
		{
			scanf("%lf", &matrix[i][j]);
			if((i == j) && !(matrix[i][j]))
			{
				printf("Gauss elimination cannot be applied.\n");
				return;
			}
		}
	}

	//Change [A:C] into upper triangular form
    // Upper triangular formation
    for (size_t k = 0; k < size_m - 1; k++)
	{
        for (size_t i = k + 1; i < size_m; i++)
		{
			if(matrix[k][k] == 0)
			{
				printf("Gauss elimination cannot proceed. There is a zero pivot at [%lu, %lu].\n", k, k);
				return;
			}
            double ratio = matrix[i][k] / matrix[k][k];
            for (size_t j = k; j < size_n; j++)
			{
                matrix[i][j] -= ratio * matrix[k][j];
            }
        }
    }
	printMatrix(matrix, size_m, size_n);
	printf("\n");
	
	// Back substitution
	for (int i = size_m - 1; i >= 0; i--)
	{
		// Check if the coefficient matrix has a row of all zeros except for the last column
		bool zero_row = true; // Assuming it's a zero row until proven otherwise
		for (unsigned j = 0; j < size_n - 1; j++)
		{
			// If a non-zero element is encountered, then it's not a zero row
			// sometimes the value is not exactly zero, but very close to zero
			if (abs(matrix[i][j]) > ZERO)
			{
				zero_row = false;
				break;
			}
		}
		if (zero_row) 
		{
			// If row is all zeros and the last column is non-zero, no solution exists
			if(abs(matrix[i][size_n - 1]) > ZERO)
				printf("No solution exists.\n");
			// If row is all zeros and the last column is also zero, infinite solutions exist
			else
				printf("Infinite solutions exist.\n");
			return;
		}

		// Perform back substitution if the coefficients indicate a single solution exists
		double sum = 0.0;
		for (size_t j = i + 1; j < size_n - 1; j++)
		{
			sum += matrix[i][j] * solution[j];
		}
		if (matrix[i][i] == 0)
		{
			printf("Gauss elimination cannot proceed. There is a zero pivot.\n");
			return;
		}
		solution[i] = (matrix[i][size_n - 1] - sum) / matrix[i][i];
	}
	//print
	printf("Solution:\n");
	for (unsigned i = 0; i < size_m; i++) { printf("x[%u] = %f\n", i + 1, solution[i]); }

	//free memory
	for(size_t i = 0; i<size_m; i++) free(matrix[i]);
	free(matrix);
}

//ooga booga brute force method for back substitution;
/*
for(size_t i = 0; i<size_m; i++)
{
	for(size_t j = 0; j<size_n; j++)
	{
		if(i == 1 && j == 0)
		{
			double ratio = matrix[i][j] / matrix[0][0];
			for(size_t k = j; k<size_n; k++)
			{
				matrix[i][k] -= ratio*matrix[i-1][k];
			}
		}

		if(i == 2 && j == 0)
		{
			double ratio = matrix[i][j] / matrix[0][0];
			for(size_t k = j; k<size_n; k++)
			{
				matrix[i][k] -= ratio*matrix[i-2][k];
			}
		}

		if(i == 2 && j == 1)
		{
			double ratio = matrix[i][j] / matrix[1][1];
			for(size_t k = j; k<size_n; k++)
			{
				matrix[i][k] -= ratio*matrix[i-1][k];
			}
		}
	}
}
*/
