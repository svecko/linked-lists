#include <iostream>
#include <list>

struct Node
{
	int data;
	Node* next;
};

static Node* s_Head = nullptr;

void PushFront(int a)
{
	Node* tmp = new Node();
	tmp->data = a;

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

void PushBack(int a)
{
	Node* tmp = new Node();
	tmp->data = a;

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

void PrintList()
{
	Node* p = s_Head;

	if (s_Head == nullptr)
	{
		std::cout << "Empty list." << std::endl;
	}
	else
	{
		while (p != nullptr)
		{
			std::cout << p->data << " ";
			p = p->next;
		}
	}

	std::cout << std::endl;
}

void Remove(int a)
{
	Node* p = s_Head;
	Node* q = nullptr;

	while (p != nullptr && p->data != a)
	{
		q = p;
		p = p->next;
	}

	if (s_Head == nullptr)
	{
		std::cout << "Empty list." << std::endl;
	}
	else if (p == nullptr)
	{
		std::cout << "Invalid number." << std::endl;
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
		std::cout << "Empty list." << std::endl;
	}
	else if (p == nullptr)
	{
		std::cout << "Invalid index." << std::endl;
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

int main()
{
	PushFront(9);
	PushBack(100);
	PushBack(1020);
	PrintList();
	Remove(9);
	PrintList();
	RemoveAtIndex(1);
	PrintList();
}