// Doubly Ended Queue implementation using Linked List
#include <cstddef>
#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* prev;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};

class Deque
{
private:
	Node* front;
	Node* rear;

public:
	Deque();
	~Deque() { delete front; delete rear; }
	void EnqueueFront(int x);
	void EnqueueRear(int x);
	int DeQueueFront();
	int DeQueueRear();
	bool IsEmpty();
	bool IsFull(Node* node);
	void Display();
};

Deque::Deque()
{
	front = rear = NULL;
}

bool Deque::IsEmpty()
{
	return front == NULL;
}

bool Deque::IsFull(Node* node)
{
	return node == NULL;
}

void Deque::EnqueueFront(int x)
{
	Node* temp = new Node(x);

	if (IsFull(temp))
	{
		cout << "Queue overflow" << endl;
		return;
	}

	if (IsEmpty())
	{
		front = rear = temp;
	}
	else
	{
		temp->next = front;
		front->prev = temp;
		front = temp;
	}
}

void Deque::EnqueueRear(int x)
{
	Node* temp = new Node(x);

	if (IsEmpty())
	{
		front = rear = temp;
		return;
	}

	temp->prev = rear;
	rear->next = temp;
	rear = temp;
}

int Deque::DeQueueFront()
{
	int x = -1;

	if (IsEmpty())
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		x = front->data;
		Node* temp = front;
		front = front->next;
		if (front != NULL)
			front->prev = NULL;
		// Means the queue has become empty
		else
			rear = NULL;
		delete temp;
	}

	return x;
}

int Deque::DeQueueRear()
{
	int x = -1;

	if (IsEmpty())
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		x = rear->data;
		Node* temp = rear;
		rear = rear->prev;
		if (rear != NULL)
			rear->next = NULL;
		// Means the queue has become empty
		else
			front = NULL;
		delete temp;
	}

	return x;
}

void Deque::Display()
{
	Node* trav = front;
	while (trav != NULL)
	{
		cout << trav->data << " ";
		trav = trav->next;
	}
	cout << endl;
}



int main()
{
	Deque* deque = new Deque();
	deque->EnqueueFront(30);
	deque->EnqueueFront(20);
	deque->EnqueueFront(10);
	deque->EnqueueRear(70);
	deque->EnqueueRear(80);
	deque->EnqueueRear(90);

	deque->Display();

	for (int i = 0; i < 3; i++)
	{
		cout << deque->DeQueueFront() << " ";
		cout << deque->DeQueueRear() << " ";
	}
	deque->DeQueueFront();
}