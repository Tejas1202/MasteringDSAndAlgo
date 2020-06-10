#include <stdio.h>

int main(void) {
    fun(3);
}

void fun(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        fun(n - 1);
        fun(n - 1);
    }
}