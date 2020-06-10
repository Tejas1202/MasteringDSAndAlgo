// Nested recursion

#include <stdio.h>

int main(void)
{
    // For any value <= 100, it'll give 91, else (n - 10)
    printf("%d\n", fun(95));
    return 0;
}

int fun(int n)
{
    if (n > 100)
        return n - 10;
    else
        return fun(fun(n + 11));
}