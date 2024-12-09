#include "linked_list.h"

void linked_list()
{
	singlyLinkedList list;
	float data;
	unsigned position;

	while(1) 
	{
		unsigned choice = 0; 
		std::cout << "\nDisplay Menu\n"
          << "(0) to insert at beginning,\n"
          << "(1) to insert at end,\n"
          << "(2) to insert at position,\n"
          << "(3) to delete from the beginning,\n"
          << "(4) to delete from the end,\n"
          << "(5) to delete from a position,\n"
          << "(6) to display the list,\n"
          << "(7) to search for data in the list\n"
          << "(8) to exit the program\n";

		std::cin>>choice; 

		switch(choice)
		{ 
			case 0:
				std::cout<<"\nEnter the data to insert at the beginning.\n";
				std::cin>>data;
				list.insert_beg(data);
				break; 
			case 1:
				std::cout<<"\nEnter the data to insert at the end.\n";
				std::cin>>data;
				list.insert_end(data);
				break;
			case 2:
				std::cout<<"Enter the position to insert data [0-n]\n";
				std::cin>>position;
				std::cout<<"Enter the data to insert at position "<<position<<".\n";
				std::cin>>data;
				list.insert_spec(data, position);
				break; 
			case 3:
				list.delete_beg();
				break;
			case 4:
				list.delete_end();
				break; 
			case 5:
				std::cout<<"Enter the position to delete data [0-n]\n";
				std::cin>>position;
				list.delete_spec(position);
				break;
			case 6:
				list.display();
				break; 
			case 7:
				std::cout<<"Enter the data to search\n";
				std::cin>>data;
				list.search(data);
				break;
			case 8:
				std::cout<<"\nProgram ended successfully\n"; 
				exit(1);
				break; 
		} 
	}
}
void linked_stack()
{
    linkedStack stack;
    float data;

    while (1)
    {
        unsigned choice = 0;
        std::cout << "\nStack Menu\n"
                  << "(0) to push data,\n"
                  << "(1) to pop data,\n"
                  << "(2) to display the stack,\n"
                  << "(3) to exit the program\n";

        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "\nEnter the data to push.\n";
            std::cin >> data;
            stack.push(data);
            break;
        case 1:
            stack.pop();
            break;
        case 2:
            stack.display();
            break;
        case 3:
            std::cout << "\nProgram ended successfully\n";
            exit(1);
            break;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
        }
    }
}
void linked_queue()
{
    linkedQueue queue;
    float data;

    while (1)
    {
        unsigned choice = 0;
        std::cout << "\nQueue Menu\n"
                  << "(0) to enqueue data,\n"
                  << "(1) to dequeue data,\n"
                  << "(2) to display the queue,\n"
                  << "(3) to exit the program\n";

        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "\nEnter the data to enqueue.\n";
            std::cin >> data;
            queue.enqueue(data);
            break;
        case 1:
            queue.dequeue();
            break;
        case 2:
            queue.display();
            break;
        case 3:
            std::cout << "\nProgram ended successfully\n";
            exit(1);
            break;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
        }
    }
}

void lab4()
{
	linked_list();
}
