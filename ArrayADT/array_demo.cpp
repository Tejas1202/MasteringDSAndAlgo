// Demo of Array ADT in C++
// Note: Not all the functions are implemented
#include <iostream>
using namespace std;

class Array
{
    // Representation/Data
private:
    int *A;
    int size;
    int length;

    // Functions kept as public
public:
    // ctor
    Array()
    {
        // Default if not specified
        size = 10;
        length = 0;
        A = new int[size];
    }

    // Parameterized ctor
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[sz];
    }

    // Destructor as we're allocating the memory dynamically here
    ~Array()
    {
        delete []A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    Array* Merge(Array arr2);
};

// Implementing all the functions by class_name scope_resolution function_name
void Array::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::Append(int x)
{
    if (length < size)
        A[length++] = x;
}

void Array::Insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index)
{
    if (index >= 0 && index < length)
    {
        int deletedElement = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        
        return deletedElement;
    }

    return 0;
}

Array* Array::Merge(Array arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array* arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = A[j++];
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = length + arr2.length;

    return arr3;
}

int main()
{
    // arr created in stack
    Array arr(10);
    arr.Insert(0, 5);
    arr.Insert(1, 6);
    arr.Insert(2, 9);
    arr.Display();
    cout << arr.Delete(0) << endl;
    arr.Display();

    // arr2 created in heap
    Array* arr2 = new Array(10);
    arr2->Insert(0, 2);
    arr2->Insert(1, 3);
    arr2->Display();
}
