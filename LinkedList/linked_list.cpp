// Singly Linked List

#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class LinkedList
{
private:
	// Head pointer
	Node* first;

public:
	LinkedList()
	{
		first = nullptr;
	}

	LinkedList(int A[], int n);
	~LinkedList();
	void Display();
	void Insert(int index, int x);
	int Delete(int index);
	int Length();
};

LinkedList::LinkedList(int A[], int n)
{
	Node* last, * temp;

	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (int i = 1; i < n; i++)
	{
		temp = new Node;
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

LinkedList::~LinkedList()
{
	Node* p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

void LinkedList::Display()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void LinkedList::Insert(int index, int x)
{
	if (index < 0 || index >= Length())
		return;

	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;

	if (index == 0)
	{
		temp->next = first;
		first = temp;
	}
	else
	{
		Node* p = first;
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}
}

int LinkedList::Delete(int index)
{
	int x = -1;
	if (index < 0 || index >= Length())
		return x;

	Node* p = first;
	if (index == 0)
	{
		x = p->data;
		first = first->next;
		delete p;
	}
	else
	{
		Node* q = NULL;
		for (int i = 0; i < index; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}

	return x;
}

int LinkedList::Length()
{
	Node* p = first;
	int length = 0;

	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}

int main()
{
	int A[] = { 5, 7, 15, 20, 25 };

	LinkedList list(A, 5);
	list.Display();

	list.Insert(0, 1);
	list.Insert(2, 10);
	list.Insert(6, 30);
	list.Display();

	cout << "Deleted Element: " << list.Delete(0) << endl;
	cout << "Deleted Element: " << list.Delete(2) << endl;
	cout << "Deleted Element: " << list.Delete(5) << endl;
	list.Display();
}