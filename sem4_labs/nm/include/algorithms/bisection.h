#pragma once
#include "definitions.h"

void bisection(double (*fn)(double))
{
	printf("Bisection Method\n");
	double x_lower, x_upper, x_mid, error_threshold;
	unsigned iter = 0;
	while(true)
	{
		printf("Enter the upper and lower bound.\n");
		scanf("%lf %lf", &x_lower, &x_upper);
		printf("Enter the desired predefined error_threshold.\n");
		scanf("%lf", &error_threshold);

		if(fn(x_lower)*fn(x_upper) < 0)
	{
			break;
		}

		printf("Initial guesses are wrong, try again\n\n");
	}
	printSeparator();
	printf("%10s %10s %10s %10s %10s %10s %10s\n", "Iteration", "x_lower", "x_upper", "f(x_lower)", "f(x_upper)", "x_mid", "f(x_mid) ");
	printSeparator();
	
	do
	{
		x_mid = (x_lower + x_upper)/2.0f;
		printf("%10d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", ++iter, x_lower, x_upper, fn(x_lower), fn(x_upper), x_mid, fn(x_mid));

		if(fn(x_mid)*fn(x_upper) < 0)
		{
			x_lower = x_mid;
		}
		else
		{
			x_upper = x_mid;
		}

	} while(abs(fn(x_mid)) > error_threshold);
	printf("The desired root below the predefined error is %0.20lf\n", x_mid);
}
