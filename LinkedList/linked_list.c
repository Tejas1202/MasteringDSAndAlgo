// Linked List Implementation
#include <stdio.h>
#include <stdlib.h>
// For getting value of INT_MIN
#include <limits.h>

// Representation of Node
struct Node
{
    int data;
    struct Node *next;
}*first = NULL;
// Creating a global pointer first and assigning it to NULL

void create(int A[], int n);
void display(struct Node *p);
void recursive_display(struct Node *p);
int count(struct Node *p);
int recursive_count(struct Node *p);
int sum(struct Node *p);
int recursive_sum(struct Node *p);
int maximum(struct Node *p);
int recursive_maximum(struct Node *p);
struct Node * linear_search(struct Node *p, int key);
struct Node* recursive_linear_search(struct Node *p, int key);
void insert(struct Node *p, int index, int x);
int delete(struct Node *p, int index);

int main(void)
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    display(first);
    printf("\n");
    recursive_display(first);
    printf("\n");
    printf("Length of linked list: %d\n", count(first));
    printf("Length of linked list using recursion: %d\n", recursive_count(first));
    printf("Sum of all elements: %d\n", sum(first));
    printf("Sum of all elements using recursion: %d\n", recursive_sum(first));
    printf("Maximum: %d\n", maximum(first));
    printf("Maximum using recursion: %d\n", recursive_maximum(first));

    struct Node *temp = linear_search(first, 4);
    if (temp != NULL)
        printf("Key found: %d\n", temp -> data);
    else
        printf("Key not found\n");
    display(first);
    printf("\n");

    temp = recursive_linear_search(first, 15);
    if (temp != NULL)
        printf("Key found: %d\n", temp -> data);
    else
        printf("Key not found\n");

    insert(first, 0, 12);
    insert(first, 3, 18);
    display(first);

    printf("Deleted element: %d\n", delete(first, 1));
    printf("Deleted element: %d\n", delete(first, 3));
    display(first);
}

// This method is like insert a new node always to last position by maintaining a pointer at last always
// So you can create a method like insert_last() which always inserts a node at the last position
void create(int A[], int n)
{
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> next = NULL;
    struct Node *temp, *last;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp -> data = A[i];
        temp -> next = NULL;
        last -> next = temp;
        last = temp;
    }
}

// We aren't directly using the first global pointer here as we always have to keep track of the head of linked list
// doing first = first -> next, we'll loose the pointer and hence loose track of all the related data in memory
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> next;
    }
}

// Change the order of printf and display if we want to print linked list in reverse order
void recursive_display(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p -> data);
        recursive_display(p -> next);
    }
}

// Returns length of a linked list
int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p -> next;
    }
    return count;
}

// Finding length using recursion
int recursive_count(struct Node *p)
{
    if (p == NULL)
        return 0;
    return 1 + recursive_count(p -> next);
}

int sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p -> data;
        p = p -> next;
    }
    return sum;
}

// Finding sum using recursion
int recursive_sum(struct Node *p)
{
    if (p == NULL)
        return 0;
    return p -> data + recursive_sum(p -> next);
}

int maximum(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if (p -> data > max)
            max = p -> data;
        p = p -> next;
    }
    return max;
}

// Finding maximum using recursion
int recursive_maximum(struct Node *p)
{
    int x = 0;

    if (p == NULL)
        return INT_MIN;
    x = recursive_maximum(p -> next);
    return x > p -> data ? x : p -> data;
}

// Linear search with Move to head improvement example
struct Node * linear_search(struct Node *p, int key)
{
    // Taking a pointer to store the p's previous node pointer
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (p -> data == key)
        {
            // Means key is at the first node itself
            if (q == NULL)
                return p;

            q -> next = p -> next;
            // Changing p's next node to point to head
            p -> next = first;
            // Making p node as head i.e. first
            first = p;
            return p;
        }
        q = p;
        p = p -> next;
    }
    return NULL;
}

struct Node* recursive_linear_search(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p -> data == key)
        return p;
    return recursive_linear_search(p -> next, key);
}

void insert(struct Node *p, int index, int x)
{
    // Check if index is valid
    if (index < 0 || index > count(p))
        return;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;

    // Inserting at head
    if (index == 0)
    {
        temp -> next = first;
        first = temp;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p -> next;
        }
        temp -> next = p -> next;
        p -> next = temp;
    }
}

int delete(struct Node *p, int index)
{
    int x = -1;
    struct Node *q = NULL;
    if (index < 1 || index > count(p))
        return x;
    if (index == 1)
    {
        q = first;
        x = first -> data;
        first = first -> next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p -> next;
        }
        q -> next = p -> next;
        x = p -> data;
        free(p);
        return x;
    }
}