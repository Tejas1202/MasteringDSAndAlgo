// Polynomial Representation, Evaluation and Addition
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term
{
    int coefficient;
    int exponent;
};

// Representation of Polynomial
struct Polynomial
{
    int no_of_terms;
    struct Term *terms;
};

void create_polynomial(struct Polynomial *p);
void display(struct Polynomial p);
struct Polynomial* add(struct Polynomial p1, struct Polynomial p2);
int evaluate_polynomial(struct Polynomial p, int x);

int main(void)
{
    struct Polynomial p1;
    create_polynomial(&p1);

    struct Polynomial p2;
    create_polynomial(&p2);

    struct Polynomial *p3;
    p3 = add(p1, p2);

    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);

    int x;
    printf("Evaluate polynomial for x: ");
    scanf("%d", &x);
    printf("Result of P(%d) is %d\n", x, evaluate_polynomial(p3, x));
}

void create_polynomial(struct Polynomial *p)
{
    printf("Enter number of terms: ");
    scanf("%d", &p -> no_of_terms);
    p -> terms = (struct Term*)malloc(p -> no_of_terms * sizeof(struct Term));

    printf("Enter coefficients and exponents for all %d terms\n", p -> no_of_terms);
    for (int i = 0; i < p -> no_of_terms; i++)
    {
        scanf("%d %d", &p -> terms[i].coefficient, &p -> terms[i].exponent);
    }
}

void display(struct Polynomial p)
{
    for (int i = 0; i < p.no_of_terms; i++)
    {
        printf("%dx%d + ", p.terms[i].coefficient, p.terms[i].exponent);
    }
    printf("\n");
}

struct Polynomial* add(struct Polynomial p1, struct Polynomial p2)
{
    struct Polynomial *sum;
    sum = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    sum -> terms = (struct Term*)malloc((p1.no_of_terms + p2.no_of_terms) * sizeof(struct Term));
    int i = 0, j = 0, k = 0;
    while (i < p1.no_of_terms && j < p2.no_of_terms)
    {
        if (p1.terms[i].exponent > p2.terms[j].exponent)
            sum -> terms[k++] = p1.terms[i++];
        else if (p1.terms[i].exponent < p2.terms[j].exponent)
            sum -> terms[k++] = p2.terms[j++];
        else
        {
            sum -> terms[k].exponent = p1.terms[i].exponent;
            sum -> terms[k++].coefficient = p1.terms[i++].coefficient + p2.terms[j++].coefficient;
        }
    }

    for (; i < p1.no_of_terms; i++)
    {
        sum -> terms[k++] = p1.terms[i];
    }
    for (; j < p2.no_of_terms; j++)
    {
        sum -> terms[k++] = p2.terms[j];
    }
    sum -> no_of_terms = k;
    return sum;
}

int evaluate_polynomial(struct Polynomial p, int x)
{
    int sum = 0;
    for (int i = 0; i < p.no_of_terms; i++)
    {
        sum  += p.terms[i].coefficient * pow(x, p.terms[i].exponent);
    }
    return sum;
}