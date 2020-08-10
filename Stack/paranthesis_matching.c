// Paranthesis Matching

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node* next;
} *top = NULL;

void push(char x);
char pop();
void display();
int is_balanced(char* expression);

int main()
{
    char* expression = "((a+b)*(c-d))";
    printf("%d\n", is_balanced(expression));
}

// Hence if we still have elements at the end of the loop or it has more ) than (, it returns false
int is_balanced(char* expression)
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
            push(expression[i]);
        else if (expression[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }

    return top == NULL;
}

void push(char x)
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

char pop()
{
    char x = -1;

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