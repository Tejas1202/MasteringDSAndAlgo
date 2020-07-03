// Sparse matrix stored in the form of 1D array
#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i; // row number
    int j; // column number
    int x; // non zero element
};

// Sparse matrix with m * n dimensions and array of Elements of size num
struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *elements;
};

void create(struct Sparse *s);
void display(struct Sparse s);
struct Sparse add(struct Sparse s1, struct Sparse s2);

int main(void)
{
    struct Sparse s1;
    create(&s1);

    struct Sparse s2;
    create(&s2);

    struct Sparse s3 = add(s1, s2);

    printf("First matrix\n");
    display(s1);
    printf("Second matrix\n");
    display(s2);
    printf("Sum matrix:\n");
    display(s3);
}

void create(struct Sparse *s)
{
    printf("Enter dimensions m n: ");
    scanf("%d%d", &s -> m, &s -> n);
    printf("Number of non zero elements: ");
    scanf("%d", &s -> num);

    s -> elements = (struct Element *)malloc(s -> num * sizeof(struct Element));
    printf("Enter all non zero elements in row number, column number, non-zero element format\n");
    // Writing non-zero values in our 1D elements array
    for (int index = 0; index < s -> num; index++)
    {
        scanf("%d%d%d", &s -> elements[index].i, &s -> elements[index].j, &s -> elements[index].x);
    }
}

void display(struct Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.elements[k].i && j == s.elements[k].j)
                printf("%d ", s.elements[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse add(struct Sparse s1, struct Sparse s2)
{
    struct Sparse s3;
    s3.m = s1.m;
    s3.n = s1.n;

    // Maximum non - zero elements will be sum if non of the row and column matches
    s3.elements = (struct Element *)malloc((s1.num + s2.num) * sizeof(struct Element));

    int i = 0, j = 0, k = 0;
    while (i < s1.num && j < s2.num)
    {
        // Check rows
        if (s1.elements[i].i < s2.elements[j].i)
            s3.elements[k++] = s1.elements[i++];
        else if (s1.elements[i].i > s2.elements[j].i)
            s3.elements[k++] = s2.elements[j++];
        else
        {
            // Check column
            if (s1.elements[i].j < s2.elements[j].j)
                s3.elements[k++] = s1.elements[i++];
            else if (s1.elements[i].j > s2.elements[j].j)
                s3.elements[k++] = s2.elements[j++];
            else
            {
                // If both row and column if equal
                s3.elements[k] = s1.elements[i];
                s3.elements[k++].x = s1.elements[i++].x + s2.elements[j++].x;
            }
        }
    }

    for (; i < s1.num; i++)
    {
        s3.elements[k++] = s1.elements[i];
    }

    for(; j < s2.num; j++)
    {
        s3.elements[k++] = s1.elements[j];
    }

    s3.num = k;

    return s3;
}