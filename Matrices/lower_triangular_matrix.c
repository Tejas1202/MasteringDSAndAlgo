// Lower Triangular Matrix implemented using 1D Array with Row/Column major mapping
#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int size;
    int *A;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
        m -> A[i*(i - 1) / 2 + (j - 1)] = x;
        //m -> A[m -> size * (j - 1) + (j - 2) * (j - 1) / 2 + (i - j)] = x;
}

int get(struct Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[i*(i - 1) / 2 + (j - 1)];
        //return m.A[m.size * (j - 1) + (j - 2) * (j - 1) / 2 + (i - j)];
    else
        return 0;
}

void display(struct Matrix m)
{
    for(int i = 1; i <= m.size; i++)
    {
        for (int j = 1; j <= m.size; j++)
        {
            if (i >= j)
                printf("%d ", m.A[i*(i - 1) / 2 + (j - 1)]);
                //printf("%d ", m.A[m.size * (j - 1) + (j - 2) * (j - 1) / 2 + (i - j)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main(void)
{
    struct Matrix m;
    printf("Enter Dimension ");
    scanf("%d", &m.size);
    int no_of_non_zero_elements = m.size * (m.size + 1) / 2;
    m.A = (int *)malloc(no_of_non_zero_elements * sizeof(int));

    printf("Enter all elements\n");
    int x;

    for (int i = 1; i <= m.size; i++)
    {
        for (int j = 1; j <= m.size; j++)
        {
            // Usage: Input 2 0 0 0, scanf will take them one by one for each row
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }
    printf("\n\n");
    display(m);
}