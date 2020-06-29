// Combination/Selection formulae (aka nCr)
#include <stdio.h>

int nCr(int n, int r);
int NCR(int n, int r);
int fact(int n);

int main(void)
{
	printf("%d\n", nCr(5, 2));
	printf("%d\n", NCR(5, 2));
}

// nCr using direct formulae
int nCr(int n, int r)
{
	int numerator = fact(n);
	int denominator = fact(r) * fact(n - r);

	return numerator / denominator;
}

// nCr using recursion
int NCR(int n, int r)
{
	if (r == 0 || n == r)
		return 1;
	return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int fact(int n)
{
	if (n == 0)
		return 1;
	return fact(n - 1) * n;
}