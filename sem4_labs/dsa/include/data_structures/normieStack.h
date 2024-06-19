#include <iostream> 
#define size 5 

class normieStack 
{ 
	public: 
		normieStack() : m_top(-1) 
		{ 
		} 

		void push(unsigned elem) 
		{ 
			if(m_top == size - 1) 
			{
				std::cout<<"Stack is full\n"; 
				return; 
			} 
			mem[++m_top] = elem;
		}

		void pop() 
		{ 
			if(m_top == -1) 
			{ 
				std::cout<<"Stack is empty\n";
				return; 
			} 
			m_top--; 
		}

		int peek() 
		{ 
			return mem[m_top];
		}

		void elements_num()
		{ 
			if(m_top != -1) std::cout<<"The total number of elements on the stack is "<<++m_top<<"\n"; 
		}

		void display() 
		{ 
			if(m_top == -1) 
			{ 
				std::cout<<"Stack is empty\n";
				return;
			}

			std::cout<<"\nThe elements of the stack are: \n";

			for(int i = m_top; i>=0; i--)
			{
				std::cout<<mem[i]<<"\n";
			} 
		} 

	private: 
		int mem[size]; 
		int m_top; 
}; 
