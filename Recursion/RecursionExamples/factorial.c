// Factorial
#include <stdio.h>

int main(void) {
	printf("%d\n", fact(5));
	printf("%d\n", iterative_fact(5));
	return 0;
}

int fact(int n)
{
    // As 0! is 1
    if(n == 0)
        return 1;
    return fact(n - 1) * n;
}

int iterative_fact(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}