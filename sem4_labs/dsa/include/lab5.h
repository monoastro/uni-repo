#include "recursive.h"

void lab5()
{
	//TOH tower(4);
	towerOfHanoi(4, 'A', 'C', 'B');

	unsigned num = 5;
	std::cout<<"\nThe fibonacci numbers are:\n";
	for(unsigned i = 0; i<num; i++) 
		std::cout<<fibonacci(i)<<"\n";

	std::cout<<"\nThe factorial of "<<num<<" is "<<factorial(num)<<".\n";
}
