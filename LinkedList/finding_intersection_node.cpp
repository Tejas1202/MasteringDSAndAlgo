// Finding Intersecting Node between two linked lists
#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

Node* first, * second;

void CreateFirst(int A[], int n)
{
	Node* temp, * tail;
	first = new Node;
	first->data = A[0];
	first->next = NULL;
	tail = first;

	for (int i = 1; i < n; i++)
	{
		temp = new Node;
		temp->data = A[i];
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

void CreateSecond(int A[], int n, Node* p)
{
	Node* temp, * tail;
	second = new Node;
	second->data = A[0];
	second->next = NULL;
	tail = second;

	for (int i = 1; i < n; i++)
	{
		temp = new Node;
		temp->data = A[i];
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
	// linking second list to first linked list's p Node
	tail->next = p;
}

void Intersection(Node* p, Node* q)
{
	stack<Node*> stack_first, stack_second;

	while (p != NULL)
	{
		stack_first.push(p);
		p = p->next;
	}
	while (q != NULL)
	{
		stack_second.push(q);
		q = q->next;
	}

	Node* r = NULL;
	while (stack_first.top() == stack_second.top())
	{
		r = stack_first.top();
		stack_first.pop();
		stack_second.pop();
	}
	
	if (r != NULL)
		cout << "Intersecting Node: " << r->data << endl;
	else
		cout << "No intersecting node" << endl;
}


int main()
{
	// Creating first linked list
	int A[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21 };
	CreateFirst(A, sizeof(A) / sizeof(A[0]));

	// Creating second linked list
	Node* temp = first;
	for (int i = 0; i < 4; i++)
	{
		temp = temp->next;
	}
	int B[] = { 2, 4, 6, 8 };
	CreateSecond(B, sizeof(B) / sizeof(B[0]), temp);

	Intersection(first, second);
}