// Operations for sorted linked list
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void display(struct Node *p);
void insert_sort(struct Node *p, int x);
int is_sorted(struct Node *p);
void remove_duplicates(struct Node *p);

int main(void)
{
    insert_sort(first, 55);
    insert_sort(first, 25);
    insert_sort(first, 25);
    insert_sort(first, 25);
    insert_sort(first, 30);
    insert_sort(first, 30);
    insert_sort(first, 60);
    display(first);
    printf("\n");
    remove_duplicates(first);
    display(first);
    printf("\n");
    printf("Is sorted: %d\n", is_sorted(first));
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> next;
    }
}

void insert_sort(struct Node *p, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        struct Node *q;

        while (p != NULL && p -> data < x)
        {
            q = p;
            p = p -> next;
        }
        // If element that we're inserting is the smallest
        if (p == first)
        {
            temp -> next = first;
            first = temp;
        }
        else
        {
            temp -> next = q -> next;
            q -> next = temp;
        }
    }
}

int is_sorted(struct Node *p)
{
    int x = INT_MIN;

    while (p != NULL)
    {
        if (p -> data < x)
            return 0;
        x = p -> data;
        p = p -> next;
    }
    return 1;
}

// Only works for sorted linked lists
void remove_duplicates(struct Node *p)
{
    struct Node *q = p -> next;

    while (q != NULL)
    {
        if (p -> data != q -> data)
        {
            p = q;
            q = q -> next;
        }
        else
        {
            p -> next = q -> next;
            free(q);
            q = p -> next;
        }
    }
}