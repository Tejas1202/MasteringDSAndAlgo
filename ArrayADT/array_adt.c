#include <stdio.h>
#include <stdlib.h>

// Representation/Data
struct Array
{
	int A[10];
	int size;
	int length;
};

// Primary operations
void display(struct Array arr);
void append(struct Array *arr, int x);
void insert(struct Array *arr, int index, int x);
int delete(struct Array *arr, int index);

// Search functions
int linear_search(struct Array *arr, int key);
int binary_search(int key);
int recursive_binary_search(int key, int low, int high);

//Swap
void swap(int *x, int *y);

// Get and Set functions
int get(struct Array arr, int index);
void set(struct Array *arr, int index, int x);

// Max, Min, Sum and Average
int max(struct Array arr);
int min(struct Array arr);
int sum(struct Array arr);
float average(struct Array arr);

// Reverse
void reverse(struct Array *arr);
void reverse_two(struct Array *arr);

// Rotation
void array_left_rotation(struct Array *arr);

// Sorting
void insert_sort(struct Array *arr, int x);
int is_sorted(struct Array arr);
void rearrange(struct Array *arr);

// Merging
struct Array* merge(struct Array first, struct Array second);

// Set Operations
void set_operations();
struct Array* Union(struct Array first, struct Array second);
struct Array* intersection(struct Array first, struct Array second);
struct Array* difference(struct Array first, struct Array second);

// Sorted array for binary search
struct Array array = {{5,8,10,12,14,20,25,28,30,35}, 10, 10};

int main()
{
	struct Array arr = {{2,4,6,8,10}, 10, 5};
	append(&arr, 14);
    insert(&arr, 5, 12);
    printf("Deleted element: %d\n", delete(&arr, 4));
	display(arr);

	// Searching
	printf("Linear search: %d\n", linear_search(&arr, 4));
	printf("Binary search: %d\n", binary_search(12));
	printf("Recursive binary search: %d\n", recursive_binary_search(30, 0, array.length - 1));

	// Reversing array
	struct Array temp = {{1,2,3,4,5}, 10, 5};
	display(temp);
	reverse(&temp);
	display(temp);
	reverse_two(&temp);
	display(temp);

	// Rotation
	array_left_rotation(&temp);
	display(temp);

	// Sorting
	struct Array tempSort = {{1,2,4,5,6}, 10, 5};
	insert_sort(&tempSort, 3);
	insert_sort(&tempSort, 0);
	display(tempSort);
	printf("%d\n", is_sorted(tempSort));
	struct Array tempArrange = {{2, -3, 25, 10, -15, -7}, 10, 6};
	rearrange(&tempArrange);
	display(tempArrange);

	// Merging
	struct Array tempA = {{3,8,16,20,25}, 10, 5};
	struct Array tempB = {{4, 10, 12, 22, 23}, 10, 5};
    	struct Array *tempMerged = merge(tempA, tempB);
    	display(*tempMerged);

    	// Set Operations
    	set_operations();
}

// A caller function to call all the set operations
void set_operations()
{
    struct Array first = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array second = {{3, 6, 7, 15, 20}, 10, 5};

    struct Array *arrayUnion = Union(first, second);
    display(*arrayUnion);

    struct Array *arrayIntersection = intersection(first, second);
    display(*arrayIntersection);

    struct Array *arrayDifference = difference(first, second);
    display(*arrayDifference);
}

void display(struct Array arr)
{
	printf("Elements are: ");
	for(int i = 0; i < arr.length; i++)
	{
		printf("%d ", arr.A[i]);
	}
	printf("\n");
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

// Gets an element at specified index
int get(struct Array arr, int index)
{
    if (index >= 0 && index <= arr.length)
        return arr.A[index];

    return -1;
}

// Sets an elements to the specified index
void set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr -> length)
        arr -> A[index] = x;
}

// Maximum
int max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

// Minimum
int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// Sum of all elements
int sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

// Average of all elements
float average(struct Array arr)
{
    return (float) sum(arr) / arr.length;
}

// Reversing using auxiliary array
void reverse(struct Array *arr)
{
    // Auxiliary array
    int *arr2 = (int *)malloc(arr -> length * sizeof(int));

    for (int i = arr -> length - 1, j = 0; i >= 0; i--,j++)
    {
        arr2[j] = arr -> A[i];
    }

    for (int i = 0; i < arr -> length; i++)
    {
        arr -> A[i] = arr2[i];
    }
}

// Reversing directly
void reverse_two(struct Array *arr)
{
    for (int i = 0, j = arr -> length - 1; i < j; i++, j--)
    {
        int temp = arr -> A[i];
        arr -> A[i] = arr -> A[j];
        arr -> A[j] = temp;
    }
}

// For left shift, we'll just leave the first index and shift all the elements to the left
void array_left_rotation(struct Array *arr)
{
    if (arr -> length > 1)
    {
        int temp = arr -> A[0];
        for (int i = 0; i < arr -> length - 1; i++)
        {
            arr -> A[i] = arr -> A[i + 1];
        }
        arr -> A[arr -> length - 1] = temp;
    }
}

// Insert an element in a sorted position in a sorted array
void insert_sort(struct Array *arr, int x)
{
    if (arr -> length < arr -> size)
    {
        int i = arr -> length - 1;
        while (i >= 0 && arr -> A[i] > x)
        {
            arr -> A[i + 1] = arr -> A[i];
            i--;
        }
        arr -> A[i + 1] = x;
        arr -> length++;
    }
}

// Checks if elements are sorted or not, 0 indicates NO
int is_sorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

// Rearranges negatives on left side and positives on right if any
void rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr -> length - 1;
    while (i < j)
    {
        while (arr -> A[i] < 0)
            i++;
        while (arr -> A[j] > 0)
            j--;
        if (i < j)
            swap(&arr -> A[i], &arr -> A[j]);
    }
}

// Note: This merging can only be done for sorted lists only
struct Array* merge(struct Array first, struct Array second)
{
    struct Array *third = (struct Array *)malloc(sizeof(struct Array));
    // Declaring three index pointers
    int i,j,k;
    i = j = k = 0;
    while (i < first.length && j < second.length)
    {
        if (first.A[i] < second.A[j])
        {
            third -> A[k++] = first.A[i++];
        }
        else
        {
            third -> A[k++] = second.A[j++];
        }
    }
    // Copy remaining elements from one or the other if any
    for(; i < first.length; i++)
    {
        third -> A[k++] = first.A[i];
    }
    for(; j < second.length; j++)
    {
        third -> A[k++] = second.A[j];
    }

    third -> length = first.length + second.length;
    third -> size = 10;

    return third;
}

// Union of two sorted arrays (duplicates in both are only copied once)
// U capitalized as union is already a keyword
struct Array* Union(struct Array first, struct Array second)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *third = (struct Array *)malloc(sizeof(struct Array));

    while (i < first.length && j < second.length)
    {
        if (first.A[i] < second.A[j])
        {
            third -> A[k++] = first.A[i++];
        }
        else if (first.A[i] > second.A[j])
        {
            third -> A[k++] = second.A[j++];
        }
        else
        {
            // Copy the element from any of the array and move both array's index pointers
            third -> A[k++] = first.A[i++];
            j++;
        }
    }
    for(; i < first.length; i++)
    {
        third -> A[k++] = first.A[i];
    }
    for(; j < second.length; j++)
    {
        third -> A[k++] = second.A[j];
    }

    third -> length = k;
    third -> size = 10;

    return third;
}

// Intersection for two sorted arrays
struct Array* intersection(struct Array first, struct Array second)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *third = (struct Array *)malloc(sizeof(struct Array));

    while (i < first.length && j < second.length)
    {
        if (first.A[i] < second.A[j])
        {
            i++;
        }
        else if (first.A[i] > second.A[j])
        {
            j++;
        }
        else
        {
            third -> A[k++] = first.A[i++];
            j++;
        }
    }

    third -> length = k;
    third -> size = 10;

    return third;
}

// Difference of two sorted arrays A - B
struct Array* difference(struct Array first, struct Array second)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *third = (struct Array *)malloc(sizeof(struct Array));

    while (i < first.length && j < second.length)
    {
        if (first.A[i] < second.A[j])
        {
            third -> A[k++] = first.A[i++];
        }
        else if (first.A[i] > second.A[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    for (; i < first.length; i++)
    {
        third -> A[k++] = first.A[i];
    }

    third -> length = k;
    third -> size = 10;

    return third;
}