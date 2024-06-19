#include <circular_queue.h>

void lab3()
{
	generalCircularQ<float> q(3);
	float val;

	while(1) 
	{
		unsigned choice = 0; 
		std::cout<<"\nDisplay Menu\n(0) to enqueue,\n(1) to dequeue,\n(2) to display,\n(3) to show total number of elements,\n(4) to exit the program\n";
		std::cin>>choice; 

		switch(choice)
		{ 
			case 0:
				std::cout<<"\nEnter element to enqueue\n";
				std::cin>>val;
				q.enqueue(val);
				break; 
			case 1:
				q.dequeue();
				break; 
			case 2:
				q.display();
				break; 
			case 3:
				q.total_elements();
				break; 
			case 4:
				std::cout<<"\nProgram ended successfully\n"; 
				exit(1);
				break; 
		} 
	}
}

