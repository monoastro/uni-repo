#include "definitions.h" //functions, cosmetics and constants are defined here

void NewtonRaphsonC(double (*fn)(double), double (*dfn)(double))
{
	printf("Newton-Raphson Method\n");
    float x_initial, epsilon, error_threshold, x_final;
    unsigned MAX_ITERATION, iter = 0;

    printf("Enter your initial guess\n");
    scanf("%f", &x_initial);
    printf("Enter error threshold:\n");
    scanf("%f", &error_threshold);
    printf("Enter MAX_ITERATION value: \n");
    scanf("%u", &MAX_ITERATION);

    printSeparator();
    printf("Iteration\t  x_0\t  f(x_0)       x_1\tf(x_1)\n");
    printSeparator();

    do
    {
        if (!dfn(x_initial))
        {
            printf("\nMathematical Error\n");
			return;
        }

        // Newton-Raphson
        x_final = x_initial - fn(x_initial) / dfn(x_initial);

        // Printing the table
        printf("%10u %10.6f %10.6f %10.6f %10.6f\n", iter, x_initial, fn(x_initial), x_final, fn(x_final));

        // Further calculations
        x_initial = x_final;

        epsilon = abs(fn(x_final));

        if (++iter == MAX_ITERATION)
        {
			printf("\nSolution does not converge below given error within the given iterations\n");
			return;
        }

    } while (epsilon > error_threshold);

    printSeparator();
	printf("\nThe value of the root is %0.8f\n", x_final);
}

