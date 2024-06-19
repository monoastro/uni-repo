#pragma once
#include "definitions.h"
#define ZERO 1e-6

void gaussJordan()
{
    unsigned size_m, size_n;
    double **matrix;

    printf("Enter the size of the augmented matrix [A:C]; row, column :\n");
    scanf("%u %u", &size_m, &size_n);

    // Allocate memory for the row
    matrix = (double**)malloc(size_m * sizeof(double*));

    // Allocate memory for the remaining elements
    for (size_t i = 0; i < size_m; i++)
        matrix[i] = (double*)malloc(size_n * sizeof(double));


    printf("Enter values of the matrix in order\n");
	//Q_singleSoln(matrix);
	//printMatrix(matrix, size_m, size_n);
	
    // Read values from user
    for (size_t i = 0; i < size_m; i++)
    {
        for (size_t j = 0; j < size_n; j++)
        {
            scanf("%lf", &matrix[i][j]);
            if ((i == j) && !(matrix[i][j]))
            {
                printf("Gauss-Jordan elimination cannot be applied.\n");
                return;
            }
        }
    }

    // Gauss-Jordan Elimination
    for (size_t k = 0; k < size_m; k++)
    {
        // Check if the pivot element is zero
        if (fabs(matrix[k][k]) < ZERO)
        {
            printf("Gauss-Jordan elimination cannot proceed.\n There is a zero pivot at [%lu, %lu].\n", k, k);
            return;
        }
			
		//divide the row by the pivot element to make the pivot element 1
        double factor = matrix[k][k];
        for (size_t j = k; j < size_n; j++)
            matrix[k][j] /= factor;

        // Make other elements in the column zero
        for (size_t i = 0; i < size_m; i++)
        {
            if (i ==  k) continue;

			double temp = matrix[i][k];
			for (size_t j = k; j < size_n; j++)
				matrix[i][j] -= temp * matrix[k][j];
        }
		/*
		printf("\n");
		printMatrix(matrix, size_m, size_n);
		printf("\n");
		*/
    }

    // Print solutions
    printf("Solution:\n");
    for (unsigned i = 0; i < size_m; i++)
        printf("x[%u] = %f\n", i + 1, matrix[i][size_n-1]);

    // Free memory
    for (size_t i = 0; i < size_m; i++)
        free(matrix[i]);
    free(matrix);
}

