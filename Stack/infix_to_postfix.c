// Infix to postfix using stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
} *top = NULL;

void push(int x);
int pop();
void display();
int precedence(char x);
int is_operand(char x);
char* infix_to_postfix(char *infix);

int main()
{
    char* infix = "a+b*c";
    char* postfix = infix_to_postfix(infix);

    printf("%s\n", postfix);
}

// Note: Here we've taken only four operators into account for demo. Real life application will have more
int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int is_operand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char* infix_to_postfix(char *infix)
{
    char* postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (is_operand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (top == NULL || precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
        postfix[j++] = pop();

    postfix[j] = '\0';

    return postfix;
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