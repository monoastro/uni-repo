//false position method

#pragma once
#include "definitions.h"

void falsePosition(double (*fn)(double))
{
	printf("False Position Method\n");
	double x_0, x_1, x_2, error_threshold;
	unsigned iter = 0;
	while(true)
	{
		printf("Enter the upper and lower bound.\n");
		scanf("%lf %lf", &x_0, &x_1);
		printf("Enter the desired predefined error_threshold.\n");
		scanf("%lf", &error_threshold);

		if(fn(x_0)*fn(x_1) < 0)
		{
			break;
		}

		printf("Initial guesses are wrong, try again\n\n");
	}
	printSeparator();
	printf("%10s %10s %10s %10s %10s %10s\n", "Iteration", "x_0", "x_1", "x_1 - x_0", "f(x_1)-f(x_0)", "f(x_0)");
	printSeparator();
	
	do
	{
		x_2 = x_0 - (fn(x_0)*(x_1 - x_0))/(fn(x_1) - fn(x_0));
		printf("%10d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", ++iter, x_0, x_1, x_1 - x_0, fn(x_1) - fn(x_0), fn(x_0));
		
		if(fn(x_2)*fn(x_1) < 0)
		{
			x_0 = x_2;
		}
		else
		{
			x_1 = x_2;
		}

	} while(abs(fn(x_2)) > error_threshold);
	printf("The desired root below the predefined error is %0.20lf\n", x_2);

}
