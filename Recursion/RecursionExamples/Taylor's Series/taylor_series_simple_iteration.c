// Taylor's series using simple iteration
#include <stdio.h>

double e(int x, int n);

int main(void)
{
	printf("%lf\n", e(1, 10));
}

// Using recursion
double e(int x, int n)
{
	double s = 1;
	int numerator = 1;
	int denominator = 1;
	for (int i = 1; i <= n; i++)
	{
		numerator *= x;
		denominator *= i;
		s += (double) numerator / denominator;
	}
	return s;
}