#include <iostream>

namespace Singly {

	struct Node
	{
		int data;
		Node* next;
	};

	static Node* s_Head = nullptr;

	void PushFront(int value)
	{
		Node* tmp = new Node();
		tmp->data = value;

		if (s_Head == nullptr)
		{
			s_Head = tmp;
			tmp->next = nullptr;
		}
		else
		{
			tmp->next = s_Head;
			s_Head = tmp;
		}
	}

	void PushBack(int value)
	{
		Node* tmp = new Node();
		tmp->data = value;

		if (s_Head == nullptr)
		{
			s_Head = tmp;
			tmp->next = nullptr;
		}
		else
		{
			Node* p = s_Head;
			while (p->next != nullptr)
			{
				p = p->next;
			}
			p->next = tmp;
			tmp->next = nullptr;
		}
	}

	void InsertSorted(int value)
	{
		Node* tmp = new Node();
		tmp->data = value;

		Node* p = s_Head;
		Node* q = nullptr;

		while (p != nullptr && p->data < value)
		{
			q = p;
			p = p->next;
		}

		if (s_Head == nullptr)
		{
			s_Head = tmp;
			tmp->next = nullptr;
		}
		else if (q == nullptr)
		{
			tmp->next = s_Head;
			s_Head = tmp;
		}
		else
		{
			q->next = tmp;
			tmp->next = p;
		}
	}

	void Remove(int value)
	{
		Node* p = s_Head;
		Node* q = nullptr;

		while (p != nullptr && p->data != value)
		{
			q = p;
			p = p->next;
		}

		if (s_Head == nullptr)
		{
			std::cout << "[WARN]: Seznam je prazen." << std::endl;
		}
		else if (p == nullptr)
		{
			std::cout << "[WARN]: Vrednosti ni v seznamu." << std::endl;
		}
		else if (q == nullptr)
		{
			s_Head = p->next;
			delete p;
		}
		else
		{
			q->next = p->next;
			delete p;
		}
	}

	void RemoveAtIndex(int index)
	{
		Node* p = s_Head;
		Node* q = nullptr;

		int indexCount = 0;

		while (p != nullptr && indexCount != index)
		{
			q = p;
			p = p->next;
			indexCount++;
		}

		if (s_Head == nullptr)
		{
			std::cout << "[WARN]: Seznam je prazen." << std::endl;
		}
		else if (p == nullptr)
		{
			std::cout << "[WARN]: Neveljaven index." << std::endl;
		}
		else if (q == nullptr)
		{
			s_Head = p->next;
			delete p;
		}
		else
		{
			q->next = p->next;
			delete p;
		}
	}

	void Print()
	{
		Node* p = s_Head;
		while (p != nullptr)
		{
			std::cout << p->data << " -> ";
			p = p->next;
		}
		std::cout << std::endl;
	}
}

namespace Doubly {

	struct Node
	{
		int data;
		Node* prev, * next;
	};

	static Node* s_Head = nullptr;
	static Node* s_Tail = nullptr;

	void PushFront(int value)
	{
		Node* tmp = new Node();
		tmp->data = value;

		if (s_Head == nullptr)
		{
			s_Head = tmp;
			s_Tail = tmp;

			tmp->prev = nullptr;
			tmp->next = nullptr;
		}
		else
		{
			tmp->next = s_Head;
			s_Head->prev = tmp;
			tmp->prev = nullptr;
			s_Head = tmp;
		}
	}

	void PushBack(int value)
	{
		Node* tmp = new Node();
		tmp->data = value;

		if (s_Head == nullptr)
		{
			s_Head = tmp;
			s_Tail = tmp;

			tmp->prev = nullptr;
			tmp->next = nullptr;
		}
		else
		{
			Node* p = s_Head;
			while (p->next != nullptr)
			{
				p = p->next;
			}
			p->next = tmp;
			tmp->prev = s_Tail;
			tmp->next = nullptr;
			s_Tail = tmp;
		}
	}

	void InsertSorted(int value)
	{
		Node* tmp = new Node();
		tmp->data = value;

		Node* p = s_Head;
		Node* q = nullptr;

		while (p != nullptr && p->data < value)
		{
			q = p;
			p = p->next;
		}

		if (s_Head == nullptr)
		{
			s_Head = tmp;
			s_Tail = tmp;

			tmp->prev = nullptr;
			tmp->next = nullptr;
		}
		else if (q == nullptr)
		{
		
			tmp->next = s_Head;
			s_Head->prev = tmp;
			tmp->prev = nullptr;
			s_Head = tmp;
		}
		else if (p == nullptr)
		{
			q->next = tmp;
			tmp->prev = q;
			tmp->next = nullptr;
			s_Tail = nullptr;
		}
		else
		{
			q->next = tmp;
			tmp->prev = q;
			tmp->next = p;
			p->prev = tmp;
		}
	}

	void Remove(int value)
	{
		Node* p = s_Head;
		Node* q = nullptr;

		while (p != nullptr && p->data != value)
		{
			q = p;
			p = p->next;
		}

		if (s_Head == nullptr)
		{
			std::cout << "[WARN]: Seznam je prazen." << std::endl;
		}
		else if (p == nullptr)
		{
			std::cout << "[WARN]: Vrednosti ni v seznamu." << std::endl;
		}
		else if (q == nullptr)
		{
			s_Head = p->next;
			p->next->prev = p->prev;
			delete p;
		}
		else if (p->next == nullptr)
		{
			q->next = p->next;
			s_Tail = p->prev;
			delete p;
		}
		else
		{
			q->next = p->next;
			p->next->prev = p->prev;
			delete p;
		}
	}

	void RemoveAtIndex(int index)
	{
		Node* p = s_Head;
		Node* q = nullptr;

		int indexCount = 0;

		while (p != nullptr && indexCount != index)
		{
			q = p;
			p = p->next;
			indexCount++;
		}

		if (s_Head == nullptr)
		{
			std::cout << "[WARN]: Seznam je prazen." << std::endl;
		}
		else if (p == nullptr)
		{
			std::cout << "[WARN]: Neveljaven index." << std::endl;
		}
		else if (q == nullptr)
		{
			s_Head = p->next;
			p->next->prev = p->prev;
			delete p;
		}
		else if (p->next == nullptr)
		{
			q->next = p->next;
			s_Tail = p->prev;
			delete p;
		}
		else
		{
			q->next = p->next;
			p->next->prev = p->prev;
			delete p;
		}
	}

	void Print()
	{
		Node* p = s_Head;
		while (p != nullptr)
		{
			std::cout << p->data << " <-> ";
			p = p->next;
		}
		std::cout << std::endl;
	}
}

int main()
{

}