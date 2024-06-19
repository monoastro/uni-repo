#pragma once
#include "definitions.h"

void secantMethod(double (*fn)(double))
{
	//what it says below
	printf("Secant Method\n");
	double x_0, x_1, x_final, epsilon, error_threshold;
    unsigned MAX_ITERATION, iter = 0;

	//input
	printf("Enter your initial guesses, x_0 and x_1\n");
	scanf("%lf %lf", &x_0, &x_1);
    printf("Enter error threshold:\n");
    scanf("%lf", &error_threshold);
    printf("Enter MAX_ITERATION value: \n");
    scanf("%u", &MAX_ITERATION);

    printSeparator();
	printf("%10s %10s %10s %10s %10s\n", "Iteration", "x_0", "x_1", "x_final", "f(x_final)");
    printSeparator();
	do
	{
		if(!(fn(x_1) - fn(x_0))) 
		{
			printf("Mathematical error detected.\n");
			return;
		}
		
		//secant method
		x_final = x_1 - (fn(x_1) * (x_1 - x_0)) / (fn(x_1) - fn(x_0));

        // Printing the table
        printf("%10u %10.6f %10.6f %10.6f %10.6f\n", iter, x_0, x_1, x_final, fn(x_final));

		//error function
		epsilon = abs((x_final - x_1) / x_final);

		//update values
		x_0 = x_1;
		x_1 = x_final;

		if(++iter == MAX_ITERATION)
		{
			printf("\nMethod doesn't converge below given error_threshold within %u iterations.\n", MAX_ITERATION);
			return;
		}
	} while(epsilon > error_threshold);
	printSeparator();

	printf("\nThe value of the root is %0.10lf\n", x_final);
}
