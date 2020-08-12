#include <cstddef>
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class Stack
{
private:
	Node* top;

public:
	Stack() { top = NULL; }
	void Push(int x);
	int Pop();
	void Display();
};

void Stack::Push(int x)
{
	Node* temp = new Node;
	if (temp == NULL)
		cout << "Stack is full" << endl;
	else
	{
		temp->data = x;
		temp->next = top;
		top = temp;
	}
}

int Stack::Pop()
{
	int x = -1;
	if (top == NULL)
		cout << "Stack is empty" << endl;
	else
	{
		x = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;
	}

	return x;
}

void Stack::Display()
{
	Node* trav = top;
	while (trav != NULL)
	{
		cout << trav->data << " ";
		trav = trav->next;
	}
	cout << endl;
}

int main()
{
	Stack stack;
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Display();

	cout << stack.Pop();
	stack.Display();
}