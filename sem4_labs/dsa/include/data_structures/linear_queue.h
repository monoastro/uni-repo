#include <iostream>

#define MAX_SIZE 5

class linearQ
{
	public:
		linearQ() : m_rear(-1)
		{
		}
		
		void enqueue(int obj)
		{
			if(m_rear == MAX_SIZE - 1)
			{
				std::cout<<"linearQ is full\n";
				return;
			}
			m_mem[++m_rear] = obj;
		}

		void dequeue()
		{
			if(-1 == m_rear)
			{
				std::cout<<"linearQ is empty\n";
				return;
			}

			for(int i = 0; i < m_rear; i++)
			{
				m_mem[i] = m_mem[i+1];
			}

			m_rear--;
		}

		void display()
		{
			if(-1 == m_rear)
			{
				std::cout<<"linearQ is empty\n";
				return;
			}
			std::cout<<"The elements of the linearQ are:\n";
			for(int i = 0; i<m_rear+1; i++)
			{
				std::cout<<m_mem[i]<<"\n";
			}
		}
		
		void total_elements()
		{
			if(-1 == m_rear)
			{
				std::cout<<"linearQ is empty\n";
				return;
			}
			std::cout<<"The total number of elements of the linearQ is "<<m_rear+1<<"\n";
		}

		int peek()
		{
			if(-1 == m_rear)
			{
				std::cout<<"linearQ is empty\n";
				return -1;
			}

			return m_mem[0];
		}

	private:
		int m_mem[MAX_SIZE];
		int m_rear;

};


class normielinearQ
{
	public:
		normielinearQ() : m_front(0), m_rear(-1)
		{
		}
		
		bool full()
		{
			return (m_rear == MAX_SIZE - 1);
		}

		bool empty()
		{
			return (m_front > m_rear);
		}

		void enqueue(int obj)
		{
			if(full())
			{
				std::cout<<"linearQ is full\n";
				return;
			}

			m_mem[++m_rear] = obj;
		}

		void dequeue()
		{
			if(empty())
			{
				std::cout<<"linearQ is empty\n";
				return;
			}

			m_front++;
		}

		void display()
		{
			if(empty())
			{
				std::cout<<"linearQ is empty\n";
				return;
			}
			std::cout<<"The elements of the linearQ are:\n";
			for(int i = m_front; i<m_rear+1; i++)
			{
				std::cout<<m_mem[i]<<"\n";
			}
		}
		
		void total_elements()
		{
			if(empty())
			{
				std::cout<<"linearQ is empty\n";
				return;
			}
			std::cout<<"The total number of elements of the linearQ is "<<m_rear - m_front + 1<<"\n";
		}

		int peek()
		{
			if(empty())
			{
				std::cout<<"linearQ is empty\n";
				return -1;
			}

			return m_mem[m_front];
		}

	private:
		int m_mem[MAX_SIZE];
		int m_front, m_rear;
};


