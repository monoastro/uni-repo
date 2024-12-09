#include "normieStack.h"
#include "generalStack.h"

void lab1()
{
	//normieStack stack;
	generalStack<int> stack(5); 
	int val;

	while(1) 
	{
		unsigned choice = 0; 
		std::cout<<"\nDisplay Menu\n(0) to push,\n(1) to pop,\n(2) to display,\n(3) to show total number of elements,\n(4) to top,\n(5) to exit\n\n";
		std::cin>>choice; 

		switch(choice)
		{ 
			case 0:
				std::cout<<"\nEnter element to push\n";
				std::cin>>val;
				stack.push(val);
				break; 
			case 1:
				stack.pop();
				break; 
			case 2:
				stack.display();
				break; 
			case 3:
				stack.elements_num();
				break; 
			case 4:
				std::cout<<"\nThe top element on the stack is "<<stack.peek()<<"\n";
				break; 
			case 5:
				std::cout<<"\nProgram ended successfully\n"; 
				exit(1);
				break; 
		} 
	}
}

