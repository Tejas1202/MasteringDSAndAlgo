// Queue implementation using LinkedList

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
} *front = NULL, *rear = NULL;

void enqueue(int x);
int dequeue();
void display();

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        enqueue(A[i]);
    }

    display();

    for (int i = 0; i < 5; i++)
    {
        printf("Dequeued element: %d\n", dequeue());
    }

    // Dequeueing on empty queue
    dequeue();
}

void enqueue(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Queue is full\n");
        return;
    }

    temp->data = x;
    temp->next = NULL;

    if (front == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int dequeue()
{
    int x = -1;

    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        x = front->data;
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }

    return x;
}

void display()
{
    struct Node* trav = front;
    while (trav != NULL)
    {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}