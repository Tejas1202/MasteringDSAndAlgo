// Array ADT using heap memory (doesn't contain all the operations, just shown how to use heap memory)
#include <stdio.h>
#include <stdlib.h>

struct Array
{
	int *A;
	int size;
	int length;
};

void display(struct Array arr);

int main()
{
	struct Array arr;
	int n;
	printf("Enter size of an array: ");
	scanf("%d", &arr.size);
	arr.A = (int *)malloc(arr.size * sizeof(int));
	arr.length = 0;

	printf("Enter number of numbers: ");
	scanf("%d", &n);

	printf("Enter all elements\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr.A[i]);
	}
	arr.length = n;

	display(arr);
}

void display(struct Array arr)
{
	printf("Elements are\n");
	for(int i = 0; i < arr.length; i++)
	{
		printf("%d ", arr.A[i]);
	}
}
