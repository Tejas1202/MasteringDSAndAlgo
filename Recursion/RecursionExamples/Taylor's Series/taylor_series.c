// Taylor's series using Recursion
#include <stdio.h>

double e(int x, int n);

int main(void)
{
	printf("%lf\n", e(1, 10));
}

double e(int x, int n)
{
	static double p = 1, f = 1;
	double r;

	if (n == 0)
		return 1;

	r = e(x, n - 1);
	p *= x;
	f *= n;
	return r + p / f;
}