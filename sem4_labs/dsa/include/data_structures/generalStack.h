#include <iostream> 

template<typename T>
class generalStack 
{ 
	public: 
		generalStack(unsigned stack_size = 10) : m_size(stack_size), m_top(-1)  
		{
			try 
			{
				mem = new T[m_size];
    		}
			catch (std::bad_alloc& e) 
			{
        		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    		}
		}

		~generalStack()
		{
			delete [] mem;
		}

		//rule 3/5/0 
		generalStack(const generalStack& other) : m_size(other.m_size), m_top(other.m_top) 
		{
			mem = new T[m_size];
			std::copy(other.mem, other.mem + m_size, mem);
		}

		generalStack& operator=(const generalStack& other) 
		{
			if (this != &other)
			{
				delete[] mem;
				m_size = other.m_size;
				m_top = other.m_top;
				mem = new T[m_size];
				std::copy(other.mem, other.mem + m_size, mem);
			}
			return *this;
		}

		void push(T elem) 
		{ 
			if(m_size - 1 == m_top) 
			{
				std::cout<<"Stack is full.\n"; 
				return; 
			} 
			mem[++m_top] = elem;
		}

		void pop() 
		{ 
			if(m_top == -1) 
			{ 
				std::cout<<"Stack is empty.\n";
				return; 
			} 
			m_top--; 
		}

		T peek() 
		{ 
			if(m_top == -1) 
			{ 
				std::cout << "nothing because the stack is empty.\n";
				return T();
			} 

			return mem[m_top];
		}

		void elements_num()
		{ 
			if(m_top != -1)
			{
				std::cout<<"The total number of elements on the stack is "<<m_top + 1<<".\n"; 
			}
			else
			{
				std::cout<<"Stack is empty.\n";
			}
		}

		void display() 
		{ 
			if(m_top == -1) 
			{ 
				std::cout<<"Stack is empty.\n";
				return;
			}

			std::cout<<"\nThe elements of the stack are: \n";

			for(int i = m_top; i>=0; i--)
			{
				std::cout<<mem[i]<<"\n";
			} 
		} 



	private: 
		int m_size;
		T *mem;
		int m_top; 
}; 

