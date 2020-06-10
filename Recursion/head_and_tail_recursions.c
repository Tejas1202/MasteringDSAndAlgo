#include <stdio.h>

int main(void) {
    int x = 3;
    funOne(x);
    printf("\n");
    funTwo(x);
	return 0;
}

// Head Recursion
void funOne(int n)
{
    if (n > 0)
    {
        funOne(n - 1);
        printf("%d", n);
    }
}

// Tail Recursion
void funTwo(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        funTwo(n - 1);
    }
}

