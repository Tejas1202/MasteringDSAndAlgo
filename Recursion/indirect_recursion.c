// Indirect recursion

#include <stdio.h>

int main(void)
{
    funA(20);
    return 0;
}

void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n / 2);
    }
}