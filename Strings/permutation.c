// Permutations of a string using BackTracking with Recursion and BruteForce
#include <stdio.h>

void perm(char *s, int k);

int main(void)
{
	char *s = "ABC";
	perm(s, 0);
}

void perm(char *s, int k)
{
    // Sizes of both arrays taken as 4 as string length is 3. So change this accordingly
    static int A[4] = {0};
    static char Result[4];

    // Printing string when reached end of recursion level
    if (s[k] == '\0')
    {
        Result[k] = '\0';
        printf("%s\n", Result);
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                // Set the character in Result array for current recursion level
                Result[k] = s[i];
                A[i] = 1;
                // Going one level deep in recursion
                perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}