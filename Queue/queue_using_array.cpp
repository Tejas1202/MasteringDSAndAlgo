// Queue implementation using Array
#include <cstddef>
#include <iostream>

using namespace std;

class Queue
{
private:
	int size;
	int front;
	int rear;
	int* Q;

public:
	Queue();
	Queue(int size);
	void Enqueue(int x);
	int Dequeue();
	void Display();
	bool IsFull();
	bool IsEmpty();
	~Queue() { delete[]Q; }
};

Queue::Queue()
{
	size = 10;
	front = rear = -1;
	Q = new int[this->size];
}

Queue::Queue(int size)
{
	this->size = size;
	front = rear = -1;
	Q = new int[this->size];
}

void Queue::Enqueue(int x)
{
	if (IsFull())
		cout << "Queue is full" << endl;
	else
	{
		rear++;
		Q[rear] = x;
	}
}

int Queue::Dequeue()
{
	int x = -1;

	if (IsEmpty())
		cout << "Queue is empty" << endl;
	else
	{
		front++;
		x = Q[front];
	}

	return x;
}

void Queue::Display()
{
	for (int i = front + 1; i <= rear; i++)
	{
		cout << Q[i] << " ";
	}
	cout << endl;
}

bool Queue::IsFull()
{
	return rear == size - 1;
}

bool Queue::IsEmpty()
{
	return front == rear;
}

int main()
{
	int size = 5;
	Queue* queue = new Queue(size);

	for (int i = 1; i <= size; i++)
		queue->Enqueue(i);

	queue->Display();

	for (int i = 1; i <= size; i++)
		cout << queue->Dequeue() << " ";

	cout << endl;
	queue->Dequeue();
}