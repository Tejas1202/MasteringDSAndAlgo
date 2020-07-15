// Circular Linked List

#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class CircularLinkedList
{
private:
	Node* head;

public:
	CircularLinkedList() { head = NULL; }
	CircularLinkedList(int A[], int n);
	~CircularLinkedList();
	void Insert(int index, int x);
	void Display();
	int Delete(int index);
	int Length();
};

CircularLinkedList::CircularLinkedList(int A[], int n)
{
	Node* last, * temp;

	head = new Node;
	head->data = A[0];
	head->next = head;
	last = head;

	for (int i = 1; i < n; i++)
	{
		temp = new Node;
		temp->data = A[i];
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

CircularLinkedList::~CircularLinkedList()
{
	Node* temp = head;
	while (temp->next != head)
	{
		temp = temp->next;
	}

	while (temp != head)
	{
		temp->next = head->next;
		delete head;
		head = temp->next;
	}

	if (temp == head)
	{
		delete head;
		head = NULL;
	}
}

void CircularLinkedList::Display()
{
	Node* temp = head;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}

void CircularLinkedList::Insert(int index, int x)
{
	if (index < 0 || index >= Length())
		return;

	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;
	Node* p = head;
	if (index == 0)
	{
		if (head == NULL)
		{
			head = temp;
			head->next = head;
		}
		else
		{
			while (p->next != head)
			{
				p = p->next;
			}
			p->next = temp;
			temp->next = head;
			head = temp;
		}
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}
}

int CircularLinkedList::Delete(int index)
{
	int x = -1;
	if (index < 0 || index >= Length())
		return -1;

	Node* p = head;
	if (index == 0)
	{
		while (p->next != head)
		{
			p = p->next;
		}

		if (p == head)
		{
			x = p->data;
			delete p;
			head = NULL;
		}
		else
		{
			p->next = head->next;
			x = head->data;
			delete head;
			head = p->next;
		}
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

int CircularLinkedList::Length()
{
	Node* p = head;
	int length = 0;
	do
	{
		length++;
		p = p->next;
	} while (p != head);

	return length;
}

int main()
{
	int A[] = { 10, 20, 30, 40, 50 };

	CircularLinkedList list(A, sizeof(A) / sizeof(A[0]));
	list.Display();

	list.Insert(0, 5);
	list.Insert(2, 25);
	list.Insert(6, 55);
	list.Display();

	cout << "Deleted Element: " << list.Delete(0) << endl;
	cout << "Deleted Element: " << list.Delete(2) << endl;
	cout << "Deleted Element: " << list.Delete(5) << endl;
	list.Display();
}