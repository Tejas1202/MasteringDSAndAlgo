// Check for LOOP in a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n);
int is_loop(struct Node* f);

int main(void)
{
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    // Creating a loop in the linked list
    t1 = first -> next -> next;
    t2 = first -> next -> next -> next -> next;
    t2 -> next = t1;

    printf("Is loop: %d\n", is_loop(first));
}

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

// If the linked list is having loop, both the pointers will meet somewhere
int is_loop(struct Node* f)
{
    // If the list is empty or contains single element
    if (f == NULL || f -> next == NULL)
        return 0;

    struct Node *p = f, *q = f;
    do
    {
        p = p -> next;
        q = q -> next;
        q = q != NULL ? q -> next : NULL;
    }
    while (p != NULL && q != NULL && p != q);

    if (p == q)
        return 1;
    else
        return 0;
}