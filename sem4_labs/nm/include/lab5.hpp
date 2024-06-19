#include "false_position.h"
#include "definitions.h"
#include "gaussElimination.h"
#include "gaussJordan.h"

/*
double fn5_2(double x) { return x*log10(x) - 1.2; }
double fn5_1(double x) { return x*x*x - 2*x - 5; }
double fn5_3(double x) { return 2*exp(x)*sin(x) - 3; }
double fn5_4(double x) { return 2*x*x*x - 2*x - 5; }
double fn5_5(double x) { return 3*x*x - 6*x + 2; } 
*/

void lab5()
{
//	falsePosition(fn5_5);
 	//gaussElimination();
	gaussJordan();
}
