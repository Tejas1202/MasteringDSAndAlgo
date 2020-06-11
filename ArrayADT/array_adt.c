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
int linear_search(struct Array *arr, int key);
void swap(int *x, int *y);
int binary_search(int key);
int recursive_binary_search(int key, int low, int high);

// Sorted array for binary search
struct Array array = {{5,8,10,12,14,20,25,28,30,35}, 10, 10};

int main()
{
	struct Array arr = {{2,4,6,8,10}, 10, 5};
	append(&arr, 14);
    insert(&arr, 5, 12);
    printf("Deleted element: %d\n", delete(&arr, 6));
    printf("Linear search: %d\n", linear_search(&arr, 4));
	display(arr);
	printf("\n");
	printf("Binary search: %d\n", binary_search(12));
	printf("Recursive binary search: %d\n", recursive_binary_search(30, 0, array.length - 1));
}

void display(struct Array arr)
{
	printf("Elements are: ");
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

// For improving linear search by Move To Front method, just replace A[i - 1] with A[0]
int linear_search(struct Array *arr, int key)
{
    for (int i = 0; i < arr -> length; i++)
    {
        if (key == arr -> A[i])
        {
            // Improving linear search by Tranposition
            swap(&arr -> A[i], &arr -> A[i - 1]);
            return i;
        }
    }
    return -1;
}

// Swap the original elements that are passed
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Binary search on a sorted array
int binary_search(int key)
{
    int low, high, mid;
    low = 0;
    high = array.length - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (key == array.A[mid])
            return mid;
        else if (key > array.A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Binary Search on a sorted array using recursion
int recursive_binary_search(int key, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == array.A[mid])
            return mid;
        else if (key < array.A[mid])
            return recursive_binary_search(key, low, mid - 1);
        else
            return recursive_binary_search(key, mid + 1, high);
    }
    return -1;
}