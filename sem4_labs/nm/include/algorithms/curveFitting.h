//curve fitting by method of least squares
#pragma once
#include "definitions.h"

#define manualInput 0

void linearCurveFitting()
{
	printf("\nLinear Curve Fitting\n");
	float **data;
	unsigned data_points; 

	float sumx = 0, sumx2 = 0, sumy = 0, sumxy = 0;
	float a, b;

	//read values from user
	#if !manualInput
	data_points = 7;
	#else
	printf("Enter the number of data points:\n");
	scanf("%u", &data_points);
	#endif

	//allocate memory for a 2D array of size data_points*2; n rows and 2 columns
	data = (float**)malloc(data_points*sizeof(float*));
	for(unsigned i = 0; i<data_points; i++) data[i] = (float*)malloc(2*sizeof(float));	

	#if !manualInput
	enterTable3c(data);
	#else 
	printf("Enter the data points in the form x y:\n");
	#endif

	//read values from user if you are masochistic
	for(unsigned i = 0; i<data_points; i++)
	{
		#if manualInput
		scanf("%f %f", &data[i][0], &data[i][1]);
		#endif
		
		//compute sums simultaneously as we input data
		sumx += data[i][0];
		sumx2 += data[i][0]*data[i][0];
		sumy += data[i][1];
		sumxy += data[i][0] * data[i][1];
	}

	printf("\nData points entered are:\n");
	//display table
	for(unsigned i = 0; i<data_points; i++) printf("(%0.0f, %0.0f)\n", data[i][0], data[i][1]);

	//free memory
	for (unsigned i = 0; i < data_points; i++) free(data[i]);
	free(data);

	//compute a and b
	b = (data_points*sumxy - sumx*sumy)/(data_points*sumx2 - sumx*sumx); 
	a = (sumy - b*sumx)/data_points;
	
	//display stuff 
	printf("\nThe values of a and b computed are %0.6f and %0.6f.\n", a, b);
	printLine(a, b);
}

void expCurveFitting()
{
	printf("\nExponential Curve Fitting\n");
	float **data;
	unsigned data_points; 

	float sumx = 0, sumx2 = 0, sumy = 0, sumxy = 0;
	float A, b;

	//read values from user
	printf("\nExponential Curve Fitting\n");
	#if !manualInput
	data_points = 7;
	#else
	printf("Enter the number of data points:\n");
	scanf("%u", &data_points);
	#endif
	
	//allocate memory
	data = (float**)malloc(data_points*sizeof(float*));
	for(unsigned i = 0; i<data_points; i++) data[i] = (float*)malloc(2*sizeof(float));
	
	#if !manualInput
	enterTable3c(data);
	#else
	printf("Enter the data points in the form x y:\n");
	#endif

	//read values from user if you are masochistic
	for(unsigned i = 0; i<data_points; i++)
	{

		#if manualInput
		scanf("%f %f", &data[i][0], &data[i][1]);
		#endif
		
		//compute sums simultaneously as we input data
		sumx += data[i][0];
		sumx2 += data[i][0]*data[i][0];
		sumy += log(data[i][1]);
		sumxy += data[i][0] * log(data[i][1]);
	}

	printf("\nData points entered are:\n");
	//display table
	for(unsigned i = 0; i<data_points; i++) printf("(%0.0f, %0.0f)\n", data[i][0], data[i][1]);

	//free memory
	for (unsigned i = 0; i < data_points; i++) free(data[i]);
	free(data);

	//compute a and b
	b = (data_points*sumxy - sumx*sumy)/(data_points*sumx2 - sumx*sumx); 
	A = (sumy - b*sumx)/data_points;

	float a = exp(A);
	
	//display stuff 
	printf("\nThe values of a and b computed are %0.6f and %0.6f.\n", a, b);
	printExp(a, b);
}
