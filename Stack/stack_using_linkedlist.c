// Stack implementation using Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
} *top = NULL;

void push(int x);
int pop();
void display();

int main()
{
    push(10);
    push(20);
    push(30);

    printf("Popped element: %d\n", pop());

    display();
}

void push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Stack is full\n");
        return;
    }

    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    int x = -1;

    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        struct Node* temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }

    return x;
}

void display()
{
    struct Node* temp = top;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}