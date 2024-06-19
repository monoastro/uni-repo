#pragma once
#include "definitions.h"

void lagrangeInterpolation()
{
	double **data, independent_value, dependent_predicition = 0;
	unsigned data_points;
	printf("Enter the number of data points:\n");
	scanf("%u", &data_points); 
	data = (double**)malloc(sizeof(double*)*data_points);
	for(unsigned i = 0; i<data_points; i++) data[i] = (double*)malloc(sizeof(double)*2);
	
	//lagrangeQ1(data);
	printf("Enter the data table in the form of x y:\n");
	for(unsigned i = 0; i<data_points; i++)
	{
		scanf("%lf %lf", &data[i][0], &data[i][1]);
	}
	
	printf("Enter the independent variable value for which the dependent variable is to be interpolated:\n");
	scanf("%lf", &independent_value);

	for(unsigned i = 0; i<data_points; i++)
	{
		double product = 1;
		for(unsigned j = 0; (j<data_points); j++)
		{
			if(j == i) continue;
			product *= (independent_value - data[j][0])/(data[i][0] - data[j][0]);
		}
		dependent_predicition += data[i][1]*product;
	}
	printf("The dependent value's predicted magnitude is %10.6lf.\n", dependent_predicition);
	for(unsigned i = 0; i<data_points; i++) free(data[i]);
	free(data);
}
