// Power/exponent m ^ n
#include <stdio.h>

int power(int m, int n)
{
    if (n == 0)
        return 1;
    return power(m, n - 1) * m;
}

// Less number of stacks and computation as compared to power function
int power_two(int m, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power_two(m * m, n / 2);
    else
        return power_two(m * m, (n - 1) / 2) * m;
}

int main(void) {
	printf("%d\n", power(2, 5));
	printf("%d\n", power_two(2, 5));
}