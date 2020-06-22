// Taylor's series with Horner's rule to reduce time complexity from O(n^2) to O(n)
#include <stdio.h>

double e(int x, int n);
double e_two(int x, int n);

int main(void)
{
	printf("%lf\n", e(1, 10));
	printf("%lf\n", e_two(1, 10));
}

// Using recursion
double e(int x, int n)
{
	static double s = 1;
	if (n == 0)
		return s;
	s = 1 + x * s / n;
	return e(x, n - 1);
}

// Using iterative loop
double e_two(int x, int n)
{
	double s = 1;
	if (n == 0)
		return s;
	for (; n > 0; n--)
	{
		s = 1 + x * s / n;
	}
	return s;
}