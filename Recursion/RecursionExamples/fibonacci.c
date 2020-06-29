// Fibonacci series
#include <stdio.h>

int i_fibonacci(int n);
int r_fibonacci(int n);
int m_fibonacci(int n);

int F[10];

int main(void)
{
	printf("%d\n", i_fibonacci(5));
	printf("%d\n", r_fibonacci(6));

	// Initializing global array F
	for (int i = 0; i < 10; i++)
	{
		F[i] = -1;
	}
	printf("%d\n", m_fibonacci(6));
}

// Using iterative version, T.C = O(n)
int i_fibonacci(int n)
{
	if (n <= 1)
		return n;

	int t0 = 0, t1 = 1, sum = 0;
	for (int i = 2; i <= n; i++)
	{
		sum = t0 + t1;
		t0 = t1;
		t1 = sum;
	}
	return sum;
}

// Using recursion, T.C = O(2^n) (example of Excessive recursion)
int r_fibonacci(int n)
{
	if (n <= 1)
		return n;
	return r_fibonacci(n - 2) + r_fibonacci(n - 1);
}

// Recursion using Memoization T.C = O(n)
int m_fibonacci(int n)
{
	if (n <= 1)
	{
		F[n] = n;
		return n;
	}
	else
	{
		if (F[n - 2] == -1)
			F[n - 2] = m_fibonacci(n - 2);
		if (F[n - 1] == -1)
			F[n - 1] = m_fibonacci(n - 1);

		F[n] = F[n - 2] + F[n - 1];
		return F[n];
	}
}