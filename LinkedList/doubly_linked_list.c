// Doubly Linked List Implementation
#include <stdio.h>
#include <stdlib.h>

// Representation of Node
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;
// Creating a global pointer first and assigning it to NULL

void create(int A[], int n);
void display(struct Node *p);
void insert(struct Node *p, int index, int x);
int delete(struct Node *p, int index);
int length(struct Node *p);
void reverse(struct Node *p);

int main(void)
{
    int A[] = { 10, 20, 30, 40, 50};
    create(A, 5);
    insert(first, 2, 25);
    insert(first, 0, 5);
    display(first);
    printf("Deleted element: %d\n", delete(first, 0));
    printf("Deleted element: %d\n" ,delete(first, 2));
    display(first);
    printf("Length is: %d\n", length(first));
    reverse(first);
    display(first);

}

void create(int A[], int n)
{
    struct Node *temp, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> prev = first -> next = NULL;
    last = first;

    // Adding nodes at the end of the linked list using last pointer
    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp -> data = A[i];
        temp -> next = last -> next;
        temp -> prev = last;
        last -> next = temp;
        last = temp;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("\n");
}

void insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > length(p))
        return;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    // Before first node
    if (index == 0)
    {
        temp -> prev = NULL;
        temp -> next = first;
        first -> prev = temp;
        first = temp;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p -> next;
        }
        temp -> prev = p;
        temp -> next = p -> next;
        if (p -> next != NULL)
        {
            p -> next -> prev = temp;
        }
        p -> next = temp;
    }
}

int delete(struct Node *p, int index)
{
    if (index < 0 || index >= length(p))
        return  -1;

    int x;
    if (index == 0)
    {
        first = first -> next;
        if (first != NULL)
        {
            first -> prev = NULL;
        }
        x = p -> data;
        free(p);
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            p = p -> next;
        }
        p -> prev -> next = p -> next;
        if (p -> next != NULL)
        {
            p -> next -> prev = p -> prev;
        }
        x = p -> data;
        free(p);
    }

    return x;
}

int length(struct Node *p)
{
    int length = 0;
    while (p != NULL)
    {
        length++;
        p = p -> next;
    }
    return length;
}

void reverse(struct Node *p)
{
    struct Node *temp;

    while (p != NULL)
    {
        // Store p's next pointer in temp as it's gonna change in next step
        temp = p -> next;
        // Reversing links
        p -> next = p -> prev;
        p -> prev = temp;
        // Move p to next node which is now in p's previous pointer after modifying
        p = p -> prev;
        if(p != NULL && p -> next == NULL)
            first = p;
    }
}