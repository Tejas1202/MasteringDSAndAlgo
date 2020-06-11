// Array ADT using stack array (stack array used to make demo easy)
#include <stdio.h>
#include <stdlib.h>

struct Array
{
	int A[10];
	int size;
	int length;
};

void display(struct Array arr);
void append(struct Array *arr, int x);
void insert(struct Array *arr, int index, int x);
int delete(struct Array *arr, int index);

int main()
{
	struct Array arr = {{2,4,6,8,10}, 10, 5};
	append(&arr, 14);
    	insert(&arr, 5, 12);
    	printf("Deleted element: %d\n", delete(&arr, 6));
	display(arr);
	printf("\n");
}

void display(struct Array arr)
{
	printf("Elements are\n");
	for(int i = 0; i < arr.length; i++)
	{
		printf("%d ", arr.A[i]);
	}
}

// As we need to change the original array, therefore calling by address
void append(struct Array *arr, int x)
{
    if (arr -> length < arr -> size)
    {
        arr -> A[arr -> length] = x;
        arr -> length++;
    }
}

// Insert an element at an given index
void insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr -> length)
    {
        for (int i = arr -> length; i > index; i--)
        {
            arr -> A[i] = arr -> A[i - 1];
        }
        arr -> A[index] = x;
        arr -> length++;
    }
}

// Deletes an element from the specified index
int delete(struct Array *arr, int index)
{
    int x = 0;

    if (index >= 0 && index < arr -> length)
    {
        x = arr -> A[index];
        for (int i = index; i < arr -> length - 1; i++)
        {
            arr -> A[i] = arr -> A[i + 1];
        }
        arr -> length--;
        return x;
    }

    return 0;
}
