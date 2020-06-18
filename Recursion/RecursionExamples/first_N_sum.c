// Sum of first N natural numbers
#include <stdio.h>

int main(void) {
	printf("%d\n", sum(15));
	printf("%d\n", iterative_sum(15));
	printf("%d\n", formula_sum(15));
	return 0;
}

// O(n) time and space
int sum(int n)
{
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}

// O(n) time and O(1) space
int iterative_sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

// O(1) time and space
int formula_sum(int n)
{
    return n * (n + 1) / 2;
}