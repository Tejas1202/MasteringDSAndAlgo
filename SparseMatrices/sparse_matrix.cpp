// Sparse Matrix
#include <iostream>
using namespace std;

// ith row jth column storing non-zero element x
class Element
{
public:
	int i;
	int j;
	int x;
};

// Sparse Matrix having m * n dimensions, and an array of Element type with size num
class Sparse
{
private:
	int m;
	int n;
	int num;
	Element* elements;

public:
	Sparse(int m, int n, int num)
	{
		this->m = m;
		this->n = n;
		this->num = num;
		elements = new Element[num];
	}

	~Sparse()
	{
		delete[] elements;
	}

	// Operator overloading => Add, cin and cout

	// Addition
	Sparse operator+(Sparse& s);
	// Extraction
	friend istream& operator>>(istream& is, Sparse& s);
	// Insertion
	friend ostream& operator << (ostream& os, Sparse& s);
};

istream& operator>>(istream& is, Sparse& s)
{
	cout << "Enter non-zero elements with row, column and element: " << endl;
	for (int i = 0; i < s.num; i++)
	{
		cin >> s.elements[i].i >> s.elements[i].j >> s.elements[i].x;
	}
	return is;
}

ostream& operator << (ostream& os, Sparse& s)
{
	int k = 0;
	for (int i = 0; i < s.m; i++)
	{
		for (int j = 0; j < s.n; j++)
		{
			if (s.elements[k].i == i && s.elements[k].j == j)
				cout << s.elements[k++].x << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	return os;
}

// Note: If you create the sum (i.e addition) matrix on stack, then upon returning to main function,
// all the values inside elements array gets deleted due to destructor. So either remove the destructor, or create the object in heap like done here
Sparse Sparse::operator+(Sparse& s)
{
	int i, j, k;
	if (m != s.m || n != s.n)
		return Sparse(0, 0, 0);

	i = j = k = 0;
	Sparse* sum = new Sparse(m, n, num + s.num);
	while (i < num && j < s.num)
	{
		if (elements[i].i < s.elements[j].i)
			sum -> elements[k++] = elements[i++];
		else if (elements[i].i > s.elements[j].i)
			sum -> elements[k++] = s.elements[j++];
		else
		{
			if (elements[i].j < s.elements[j].j)
				sum -> elements[k++] = elements[i++];
			else if (elements[i].j > s.elements[j].j)
				sum -> elements[k++] = s.elements[j++];
			else
			{
				sum -> elements[k] = elements[i];
				sum -> elements[k++].x = elements[i++].x + s.elements[j++].x;
			}
		}
	}
	for (; i < num; i++)
	{
		sum -> elements[k++] = elements[i];
	}
	for (; j < s.num; j++)
	{
		sum -> elements[k++] = s.elements[j];
	}

	return *sum;
}

int main()
{
	Sparse s1(5, 5, 5);
	Sparse s2(5, 5, 5);
	
	cin >> s1;
	cin >> s2;

	Sparse sum = s1 + s2;

	cout << "First Matrix" << endl << s1;
	cout << "Second Matrix" << endl << s2 ;
	cout << "Sum Matrix" << endl << sum;
}