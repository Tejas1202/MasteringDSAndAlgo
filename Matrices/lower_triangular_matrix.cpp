// Lower Triangular Matrix implemented using 1D array with Row/Column Major Mapping
#include <iostream>
using namespace std;

class Matrix
{
private:
	int size;
	int* A;
	int RowMajorIndex(int i, int j);
	int ColumnMajorIndex(int i, int j);

public:
	Matrix()
	{
		size = 2;
		A = new int[size * (size + 1) / 2];
	}

	Matrix(int size)
	{
		this -> size = size;
		A = new int[size * (size + 1) / 2];
	}

	~Matrix()
	{
		delete[]A;
	}

	int Get(int i, int j);
	void Set(int i, int j, int x);
	void Display();
};

int Matrix::Get(int i, int j)
{
	if (i >= j)
		return A[RowMajorIndex(i, j)];
	return 0;
}

void Matrix::Set(int i, int j, int x)
{
	if (i >= j)
		A[RowMajorIndex(i, j)] = x;
}

void Matrix::Display()
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (i >= j)
				cout << A[RowMajorIndex(i, j)] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

int Matrix::RowMajorIndex(int i, int j)
{
	return i * (i - 1) / 2 + (j - 1);
}

int Matrix::ColumnMajorIndex(int i, int j)
{
	return size * (j - 1) - ((j - 2) * (j - 1) / 2) + (i - j);
}

int main()
{
	int dimension;
	cout << "Enter Dimension ";
	cin >> dimension;

	Matrix matrix(dimension);
	int x;
	cout << "Enter all elements:" << endl;

	for (int i = 1; i <= dimension; i++)
	{
		for (int j = 1; j <= dimension; j++)
		{
			cin >> x;
			matrix.Set(i, j, x);
		}
	}
	
	cout << "Lower Triangular Matrix:" << endl;
	matrix.Display();
}