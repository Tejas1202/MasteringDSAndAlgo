// Polynomial representation using LinkedList

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exponent;
    struct Node* next;
} *poly = NULL;

void create();
void display(struct Node *p);
int evaluate(struct Node *p, int x);


int main()
{
    create();
    display(poly);
    printf("Evaluation: %d\n", evaluate(poly, 1));
}

void create()
{
    struct Node* temp, * last;
    int num;
    printf("Enter number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp\n");

    for (int i = 0; i < num; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d%d", &temp->coeff, &temp->exponent);
        temp->next = NULL;
        if (poly == NULL)
        {
            poly = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%dx%d +", p->coeff, p->exponent);
        p = p->next;
    }
    printf("\n");
}

int evaluate(struct Node *p, int x)
{
    int result = 0;
    while(p)
    {
        result += p->coeff * pow(x, p->exponent);
        p = p->next;
    }
    return result;
}