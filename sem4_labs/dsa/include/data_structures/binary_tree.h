#include <iostream>

class Node
{
public:
    int m_data;
    Node* m_leftSon;
    Node* m_rightSon;

    Node(int data = 0) : m_data(data), m_leftSon(nullptr), m_rightSon(nullptr) {}
};

class BinaryTree
{
public:
    BinaryTree() : m_root(nullptr) {}
    ~BinaryTree() { destroy_tree(m_root); }

	bool search(int data) { return search(m_root, data); }
    void Delete(int data) { Delete(m_root, data); }
    void inorder_print() { inorder_print(m_root); }
    void postorder_print() { postorder_print(m_root); }
    void preorder_print() { preorder_print(m_root); }

	void insert(int data) 
	{
		if(search(data)) 
		{
			std::cout<<"Duplicate data "<<data<<"\n";
			return;
		}
		insert(m_root, data); 
	}

private:
    void insert(Node*& node, int data)
	{
        if (!node)
		{ 
			node = new Node(data);
			return;
		}

		if (data < node->m_data) { insert(node->m_leftSon, data); }
		else { insert(node->m_rightSon, data); }
    }
    bool search(Node* node, int data)
	{
        if (!node) return false;
        if (data == node->m_data) return true;

		else if (data < node->m_data) return search(node->m_leftSon, data);
		else return search(node->m_rightSon, data);
    }

	void preorder_print(Node* node)
	{
		if (!node) return;

		std::cout << node->m_data << " ";
		preorder_print(node->m_leftSon);
		preorder_print(node->m_rightSon);
	}

    void inorder_print(Node* node)
	{
        if (!node) return;

		inorder_print(node->m_leftSon);
		std::cout << node->m_data << " ";
		inorder_print(node->m_rightSon);
    }
    void postorder_print(Node* node)
	{
        if (!node) return;

		postorder_print(node->m_leftSon);
		postorder_print(node->m_rightSon);
		std::cout << node->m_data << " ";
    }

    void destroy_tree(Node*& node)
	{
        if (!node) return;

		destroy_tree(node->m_leftSon);
		destroy_tree(node->m_rightSon);
		delete node;
		node = nullptr;
    }

	Node* findMin(Node* node)
	{
		// Check if the node is nullptr
		if (node == nullptr) {
			return nullptr;
		}

		while (node->m_leftSon) {
			node = node->m_leftSon;
		}
		return node;
	}
	
	Node* Delete(Node *node, int data)
	{
		if (!node)
		{
			std::cout << "Tree is empty or data not found\n";
			return nullptr;
		}

		if (data < node->m_data)
		{
			node->m_leftSon = Delete(node->m_leftSon, data);
		}
		else if (data > node->m_data)
		{
			node->m_rightSon = Delete(node->m_rightSon, data);
		}
		else
		{
			// Case 1: Node with no child (leaf node)
			if (!node->m_leftSon && !node->m_rightSon)
			{
				delete node;
				return nullptr;
			}
			// Case 2: Node with one child
			else if (!node->m_leftSon)
			{
				Node* temp = node->m_rightSon;
				delete node;
				return temp;
			}
			else if (!node->m_rightSon)
			{
				Node* temp = node->m_leftSon;
				delete node;
				return temp;
			}
			// Case 3: Node with two children
			else
			{
				Node* temp = findMin(node->m_rightSon);
				node->m_data = temp->m_data;
				node->m_rightSon = Delete(node->m_rightSon, temp->m_data);
			}
		}
		return node;
	}

	Node* m_root;
};
