// Stack implementation using Array

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *A;
};

void create(struct Stack* stack);
void display(struct Stack stack);
void push(struct Stack* stack, int x);
int pop(struct Stack* stack);
int peek(struct Stack stack, int index);
int is_empty(struct Stack stack);
int is_full(struct Stack stack);
int stack_top(struct Stack stack);

int main()
{
    struct Stack stack;
    create(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("Peek: %d\n", peek(stack, 1));
    printf("Peek: %d\n", peek(stack, 3));

    printf("Popped element: %d\n", pop(&stack));

    display(stack);
}

void create(struct Stack* stack)
{
    printf("Enter size: ");
    scanf("%d", &stack->size);
    stack->top = -1;
    stack->A = (int *)malloc(stack->size * sizeof(int));
}

void display(struct Stack stack)
{
    for (int i = stack.top; i >= 0; i--)
    {
        printf("%d ", stack.A[i]);
    }
    printf("\n");
}

void push(struct Stack* stack, int x)
{
    if (stack->top == stack->size-1)
        printf("Stack overflow\n");
    else
    {
        stack->top++;
        stack->A[stack->top] = x;
    }
}

int pop(struct Stack* stack)
{
    int x = -1;

    if (stack->top == -1)
        printf("Stack underflow\n");
    else
        x = stack->A[stack->top--];

    return x;
}

// Peeks an element from the top at specified index
int peek(struct Stack stack, int index)
{
    int x = -1;
    if (stack.top - index + 1 < 0)
        printf("Invalid index \n");
    else
        x = stack.A[stack.top - index + 1];

    return x;
}

int is_empty(struct Stack stack)
{
    if (stack.top == -1)
        return 1;
    else
        return 0;
}

int is_full(struct Stack stack)
{
    return stack.top == stack.size - 1;
}

int stack_top(struct Stack stack)
{
    if (!is_empty(stack))
        return stack.A[stack.top];
    return -1;
}