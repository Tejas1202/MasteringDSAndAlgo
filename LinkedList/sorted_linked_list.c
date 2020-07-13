// Operations for sorted linked list
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL;

void display(struct Node *p);
void insert_sort(struct Node *p, int x);
void insert_sort_second(struct Node *p, int x);
int is_sorted(struct Node *p);
void remove_duplicates(struct Node *p);
void concat(struct Node *p, struct Node *q);
void merge(struct Node *p, struct Node *q);

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
    remove_duplicates(first);
    display(first);
    printf("Is sorted: %d\n", is_sorted(first));

    insert_sort_second(second, 28);
    insert_sort_second(second, 38);
    insert_sort_second(second, 52);
    insert_sort_second(second, 58);
    insert_sort_second(second, 62);
    insert_sort_second(second, 68);
    display(second);

    //concat(first, second);
    merge(first, second);
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

// Created same method for inserting into second global pointer
void insert_sort_second(struct Node *p, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
    if (second == NULL)
    {
        second = temp;
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
        if (p == second)
        {
            temp -> next = second;
            second = temp;
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

void concat(struct Node *p, struct Node *q)
{
    struct Node *concat_list = p;
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = q;
    printf("Concatinated linked list:\n");
    display(concat_list);
}

void merge(struct Node *p, struct Node *q)
{
    struct Node *third = NULL, *last = NULL;

    // Set the third and last pointer to the first or second list whichever's first element is smaller
    if (p -> data < q -> data)
    {
        third = last = p;
        p = p -> next;
        third -> next = NULL;
    }
    else
    {
        third = last = q;
        q = q -> next;
        third -> next = NULL;
    }

    while (p != NULL && q != NULL)
    {
        if (p -> data < q -> data)
        {
            last -> next = p;
            last = p;
            p = p -> next;
            last -> next = NULL;
        }
        else
        {
            last -> next = q;
            last = q;
            q = q -> next;
            last -> next = NULL;
        }
    }

    // No need for while loop as one or more elements will just be linked altogether like concatenation
    if (p != NULL)
    {
        last -> next = p;
    }
    if (q != NULL)
    {
        last -> next = q;
    }

    display(third);
}