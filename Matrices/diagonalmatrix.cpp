#include <iostream>
using namespace std;

class Diagonal
{
    // Representation/Data
private:
    int size;
    int* A;

    // Functions kept as public
public:
    // Default ctor
    Diagonal()
    {
        size = 2;
        A = new int[size];
    }

    // Parameterized ctor
    Diagonal(int size)
    {
        this -> size = size;
        A = new int[size];
    }

    // Destructor as we're allocating the memory dynamically here
    ~Diagonal()
    {
        delete []A;
    }

    int Get(int i, int j);
    void Set(int i, int j, int x);
    void Display();
};

// Implementing all the functions by class_name scope_resolution function_name
int Diagonal::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    return 0;
}

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

void Diagonal::Display()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    Diagonal diagonal(4);
    diagonal.Set(1, 1, 5);
    diagonal.Set(2, 2, 8);
    diagonal.Set(3, 3, 9);
    diagonal.Set(4, 4, 12);
    diagonal.Display();
}