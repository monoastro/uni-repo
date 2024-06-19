#include "binary_tree.h"

void lab6()
{
	//bst.insert(40);
	//bst.insert(50);
	//bst.insert(30);
	//bst.insert(20);
	//bst.insert(15);
	//bst.insert(10);
	//bst.insert(5);
	//bst.insert(90);
	//bst.insert(45);
	//bst.insert(35);
	//bst.insert(22);
	//bst.insert(17);

	BinaryTree bst;
	int data;

	while(1) 
	{
		unsigned choice = 0; 
		std::cout << "\nDisplay Menu\n"
          << "(0) to insert data,\n"
          << "(1) to delete data,\n"
          << "(2) to display in preorder,\n"
		  << "(3) to display in inorder,\n"
          << "(4) to display in postorder,\n"
          << "(5) to exit the program\n";
		std::cin>>choice; 

		switch(choice)
		{ 
			case 0:
				std::cout<<"\nEnter the data to insert.\n";
				std::cin>>data;
				bst.insert(data);
				break; 
			case 1:
				std::cout<<"\nEnter the data to delete.\n";
				std::cin>>data;
				bst.Delete(data);
				break;
			case 2:
				std::cout<<"The preorder traversal is: \n";
				bst.preorder_print();
				std::cout<<"\n";
				break; 
			case 3:
				std::cout<<"The inorder traversal is: \n";
				bst.inorder_print();
				std::cout<<"\n";
				break;
			case 4:
				std::cout<<"The postorder traversal is: \n";
				bst.postorder_print();
				std::cout<<"\n";
				break; 
			case 5:
				std::cout<<"\nProgram ended successfully\n"; 
				exit(1);
				break; 
		} 
	}
}
