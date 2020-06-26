// Checking for duplicates using Hash table
// Note: Algo assumes that all the characters are in lowercase
// If you want to make it generic for all the cases, then consider making your array size as 122
#include <stdio.h>

int main(void)
{
	char *s = "finding";
	int H[26] = {0};

	for (int i = 0; s[i] != '\0'; i++)
	{
		H[s[i] - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (H[i] > 1)
		{
			printf("Letter %c repeated %d times\n", (i + 97), H[i]);
		}
	}
}