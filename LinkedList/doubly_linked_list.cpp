// Doubly Linked List

#include <iostream>
using namespace std;

class Node
{
public:
	Node* prev;
	int data;
	Node* next;
};

class DoublyLinkedList
{
private:
	Node* head;

public:
	DoublyLinkedList() { head = NULL; }
	DoublyLinkedList(int A[], int n);
	~DoublyLinkedList();
	void Insert(int index, int x);
	void Display();
	int Delete(int index);
	int Length();
	void Reverse();
};

DoublyLinkedList::DoublyLinkedList(int A[], int n)
{
	Node* tail, * temp;
	head = new Node;
	head->data = A[0];
	head->prev = head->next = NULL;
	tail = head;

	for (int i = 1; i < n; i++)
	{
		temp = new Node;
		temp->data = A[i];
		temp->prev = tail;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* p = head;
	while (head != NULL)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

void DoublyLinkedList::Display()
{
	Node* p = head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void DoublyLinkedList::Insert(int index, int x)
{
	if (index < 0 || index >= Length())
		return;

	Node* temp = new Node;
	temp->data = x;

	if (index == 0)
	{
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
	{
		Node* p = head;
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		temp->next = p->next;
		temp->prev = p;
		if (p->next != NULL)
		{
			p->next->prev = temp;
		}
		p->next = temp;
	}
}

int DoublyLinkedList::Delete(int index)
{
	int x = -1;
	if (index < 0 || index >= Length())
		return x;

	Node* p = head;
	if (index == 0)
	{
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		x = p->data;
		delete p;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		p->prev->next = p->next;
		if (p->next != NULL)
		{
			p->next->prev = p->prev;
		}
		x = p->data;
		delete p;
	}

	return x;
}

int DoublyLinkedList::Length()
{
	int length = 0;
	Node* p = head;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}

	return length;
}

void DoublyLinkedList::Reverse()
{
	Node* p = head;
	Node* temp;
	while (p != NULL)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;

		if (p->next == NULL)
		{
			p->next = p->prev;
			p->prev = NULL;
			head = p;
			break;
		}
	}
}

int main()
{
	int A[] = { 10, 20, 30, 40, 50 };

	DoublyLinkedList dll(A, sizeof(A) / sizeof(A[0]));
	cout << "Length: " << dll.Length() << endl;

	dll.Insert(0, 5);
	dll.Insert(5, 55);
	dll.Display();

	dll.Delete(0);
	dll.Delete(5);
	dll.Display();

	dll.Reverse();
	dll.Display();

	return 0;
}