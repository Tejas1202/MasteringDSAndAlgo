// Finding middle element in a singly linked list
#include <iostream>
#include <stack>
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
	Node* head;

public:
	LinkedList(int A[], int n)
	{
		Node* temp, * tail;
		head = new Node;
		head->data = A[0];
		head->next = NULL;
		tail = head;

		for (int i = 1; i < n; i++)
		{
			temp = new Node;
			temp->data = A[i];
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}
	}

	// Takes two scans
	void MiddleNode1()
	{
		Node* p = head;
		int length = 0;
		while (p != NULL)
		{
			length++;
			p = p->next;
		}
		int index = (int) ceil(length / 2.0);
		p = head;
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		cout << "Middle element: " << p->data << endl;
	}

	// Takes single scan
	void MiddleNode2()
	{
		Node* p, * q;
		p = q = head;
		while (q)
		{
			q = q->next;
			if (q)
				q = q->next;
			if (q)
				p = p->next;
		}
		cout << "Middle element: " << p->data << endl;
	}

	// Using stack
	void MiddleNode3()
	{
		Node* p = head;
		// Creating stack of Node pointers
		stack<Node*> stack;
		while (p != NULL)
		{
			stack.push(p);
			p = p->next;
		}
		int length = stack.size();
		int pop_length = (int) floor(length / 2.0);
		while (pop_length)
		{
			stack.pop();
			pop_length--;
		}
		cout << "Middle Element: " << stack.top()->data << endl;
	}
};

int main()
{
	int A[] = { 2, 4, 6, 8, 10 };
	LinkedList list(A, sizeof(A) / sizeof(A[0]));
	list.MiddleNode1();
	list.MiddleNode2();
	list.MiddleNode3();
}