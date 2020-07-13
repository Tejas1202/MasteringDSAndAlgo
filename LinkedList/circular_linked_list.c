// Circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n);
void display(struct Node *h);
void recursive_display(struct Node *h);
void insert(struct Node *p, int index, int x);
int delete(struct Node *p, int index);
int length(struct Node *p);

int main(void)
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    display(head);

    insert(head, 2, 10);
    insert(head, 0, 11);
    recursive_display(head);
    printf("\n");

    printf("Element deleted: %d\n", delete(head, 0));
    printf("Element deleted: %d\n", delete(head, 2));
    display(head);
}

void create(int A[], int n)
{
    struct Node *temp = NULL, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head -> data = A[0];
    head -> next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp -> data = A[i];
        temp -> next = last -> next;
        last -> next = temp;
        last = temp;
    }
}

// using while loop would've made the condition false in the first iteration itself
void display(struct Node *h)
{
    do
    {
        printf("%d ", h -> data);
        h = h -> next;
    }
    while (h != head);
    printf("\n");
}

void recursive_display(struct Node *h)
{
    static int flag = 0;
    if (h != head || flag == 0)
    {
        flag = 1;
        printf("%d ", h -> data);
        recursive_display(h -> next);
    }
}

void insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > length(p))
        return;

    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;

    // inserting at head
    if (index == 0)
    {
        // if list in null
        if (head == NULL)
        {
            head = temp;
            head -> next = head;
        }
        else
        {
            while (p -> next != head)
            {
                p = p -> next;
            }
            p -> next = temp;
            temp -> next = head;
            head = temp;
        }
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
    if (index < 0 || index > length(p))
        return -1;

    int x;
    // Deleting head node
    if (index == 0)
    {
        while (p -> next != head)
        {
            p = p -> next;
        }
        x = head -> data;
        if (p == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p -> next = head -> next;
            free(head);
            head = p -> next;
        }
    }
    else
    {
        struct Node *q;
        for (int i = 0; i < index - 1; i++)
        {
            p = p -> next;
        }
        q = p -> next;
        p -> next = q -> next;
        x = q -> data;
        free(q);
    }

    return x;
}

int length(struct Node *p)
{
    int length = 0;
    do
    {
        length++;
        p = p -> next;
    }
    while(p != head);

    return length;
}