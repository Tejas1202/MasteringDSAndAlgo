#include <stdio.h>

// int x = 0; (Same with global)

int main(void) {
    printf("%d\n", sum(5));
    printf("%d\n", sumTwo(5));
}

// Sum of 0 to n integers
int sum(int n)
{
    if (n > 0)
    {
        return sum(n - 1) + n;
    }
    return 0;
}

// Using static variable in recursion
int sumTwo(int n)
{
    static int x;
    if (n > 0)
    {
        x++;
        return sumTwo(n - 1) + x;
    }
    return 0;
}