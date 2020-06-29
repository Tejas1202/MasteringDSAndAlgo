// Tower Of Hanoi problem using Recursion
#include <stdio.h>

void TOH(int n, int A, int B, int C);

int main(void)
{
	int no_of_disks;
	printf("No. of Disks: ");
	scanf("%d", &no_of_disks);
	TOH(no_of_disks, 65, 66, 67);
}

void TOH(int n, int A, int B, int C)
{
	if (n > 0)
	{
		TOH(n - 1, A, C, B);
		printf("%c to %c\n", A, C);
		TOH(n - 1, B, A, C);
	}
}