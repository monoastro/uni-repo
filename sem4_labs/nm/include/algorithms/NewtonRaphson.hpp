#include "definitions.h"

void NewtonRaphsonCpp(double (*fn)(double), double (*dfn)(double))
{
	std::cout<<"Newton Raphson Method cpp\n";
	float x_initial, epsilon, error_threshold, x_final;
	unsigned MAX_ITERATION, iter = 0;
	std::cout<<"Enter your initial guess\n";
	std::cin>>x_initial;
	std::cout<<"Enter error threshold:\n";
	std::cin>>error_threshold;
	std::cout<<"Enter MAX_ITERATION value: \n";
	std::cin>>MAX_ITERATION;

	printSeparator();
    printf("Iteration\t  x_0\t  f(x_0)       x_1\tf(x_1)\n");
	printSeparator();

	do
	{
		if(!dfn(x_initial))
		{
			std::cout<<"\nMathematical Error\n";
			return;
		}

		x_final = x_initial - fn(x_initial)/dfn(x_initial);
	
		//printing the table
        printf("%10u %10.6f %10.6f %10.6f %10.6f\n", iter, x_initial, fn(x_initial), x_final, fn(x_final));

		//further calc
		x_initial = x_final;
		
		epsilon = abs(fn(x_final));
		if(++iter == MAX_ITERATION)
		{
			printf("\nSolution does not converge below given error within the given iterations\n");
			return;
		}

	} while(epsilon > error_threshold);
	printSeparator();
    printf("\nThe value of the root is %0.8f\n", x_final);
}
