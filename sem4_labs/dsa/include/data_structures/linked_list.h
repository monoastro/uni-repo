#include <iostream>

struct Node
{
    float m_data;
    Node* m_next;
    Node(float data = 0) : m_data(data), m_next(nullptr) {}
};

class singlyLinkedList
{
public:
    singlyLinkedList() : m_head(nullptr) {}

    void insert_beg(float data)
	{
        Node* new_node = new Node(data);
        new_node->m_next = m_head;
        m_head = new_node;
    }

    void insert_end(float data)
	{
		//if list is empty
		if (!m_head)
		{
			insert_beg(data);
			return;
		}
		
		//otherwise if non-empty
		Node* new_node = new Node(data);
		Node* current = m_head;
		while (current->m_next) current = current->m_next; //traverse to the end
		current->m_next = new_node;
	}

    void insert_spec(float data, unsigned position)
	{
		//if position is 0; there is no situation where
		//the user shouldn't be able to insert if position is 0
        if (!position)
		{
			insert_beg(data);
            return;
        }

		//otherwise if position is non-zero
		//this includes the case where the list is empty and invalid positions
		Node* new_node = new Node(data);
        Node* current = m_head;
        for (unsigned i = 1; i < position && current; ++i) current = current->m_next;
        if (!current)
		{
            std::cerr << "Invalid position.\n";
			delete new_node;
            return;
        }
        new_node->m_next = current->m_next;
        current->m_next = new_node;
    }

    void delete_beg()
	{
        if (!m_head)
		{
			std::cerr << "List is empty.\n";
			return;
        }
		Node* temp = m_head;
		m_head = m_head->m_next;
		delete temp;
    }

    void delete_end()
	{
		//if list is empty or has only one element
        if (!m_head || !m_head->m_next)
		{
			delete_beg();
			return;
        }

        Node* current = m_head;
        while (current->m_next->m_next) current = current->m_next;
        delete current->m_next;
        current->m_next = nullptr;
    }

    void delete_spec(unsigned position)
	{
		//no situation where this doesn't apply with delete_beg()
        if (!position)
		{
            delete_beg();
            return;
        }

        Node* current = m_head;
        for (unsigned i = 1; i < position && current; ++i) current = current->m_next;
        if (!current || !current->m_next)
		{
            std::cerr << "Invalid position." << std::endl;
            return;
        }
        Node* temp = current->m_next;
        current->m_next = current->m_next->m_next;
        delete temp;
    }

    void display()
	{
        Node* current = m_head;
		//if (!current)
		//{
		//	std::cerr << "List is empty.\n";
		//	return;
		//}
		std::cout<<"The data in the list is: \n";
        while (current)
		{
            std::cout << current->m_data << " ";
            current = current->m_next;
        }
        std::cout << "\n";
    }

	void search(float data)
	{
		unsigned position = 0;
		Node *current = m_head;
		while (current)
		{
			if(current->m_data == data) 
			{
				std::cout<<"Data was found at position "<<position<<"\n";
				return;
			}
			position++;
			current = current->m_next;
		}
		std::cout<<"Data is not in the list.\n";
	}

    ~singlyLinkedList()
	{
        Node* current = m_head;
        while (current)
		{
            Node* next = current->m_next;
            delete current;
            current = next;
        }
    }

private:
    Node* m_head;
};

class linkedStack
{
public:
    linkedStack() : m_top(nullptr) {}

    void push(float data)
    {
        Node* new_node = new Node(data);
        new_node->m_next = m_top;
        m_top = new_node;
    }

    void pop()
    {
        if (!m_top)
        {
			std::cerr << "Stack is empty. Cannot pop.\n";
			return;
        }
		Node* temp = m_top;
		m_top = m_top->m_next;
		delete temp;
    }

    void display()
    {
        Node* current = m_top;
        if (!current)
        {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "The data in the stack is: \n";
        while (current)
        {
            std::cout << current->m_data << " ";
            current = current->m_next;
        }
        std::cout << "\n";
    }

    ~linkedStack()
    {
        Node* current = m_top;
        while (current)
        {
            Node* next = current->m_next;
            delete current;
            current = next;
        }
    }

private:
    Node* m_top;
};

class linkedQueue
{
public:
    linkedQueue() : m_front(nullptr), m_rear(nullptr) {}

    void enqueue(float data)
    {
        Node* new_node = new Node(data);
        if (!m_front)
        {
            m_front = new_node;
            m_rear = new_node;
        }
        else
        {
            m_rear->m_next = new_node;
            m_rear = new_node;
        }
    }

    void dequeue()
    {
        if (!m_front)
        {
			std::cerr << "linkedQueue is empty. Cannot dequeue.\n";
			return;
		}

		Node* temp = m_front;
		m_front = m_front->m_next;
		delete temp;

		if (!m_front) // If the queue becomes empty after dequeue
		{
			m_rear = nullptr;
		}
    }

    void display()
    {
        Node* current = m_front;
        if (!current)
        {
            std::cout << "linkedQueue is empty.\n";
            return;
        }
        std::cout << "The data in the queue is: \n";
        while (current)
        {
            std::cout << current->m_data << " ";
            current = current->m_next;
        }
        std::cout << "\n";
    }

    ~linkedQueue()
    {
        Node* current = m_front;
        while (current)
        {
            Node* next = current->m_next;
            delete current;
            current = next;
        }
    }

private:
    Node* m_front;
    Node* m_rear;
};
