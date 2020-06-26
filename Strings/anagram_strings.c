// Check if strings are Anagram using Hash table
// Assume both strings are in lowercase
#include <stdio.h>

int main(void)
{
	char *s = "observe";
	char *t = "verbose";
	char H[26] = {0};
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		H[s[i] - 97] ++;
	}
	for (i = 0; t[i] != '\0'; i++)
	{
		H[t[i] - 97]--;
		if (H[t[i] - 97] < 0)
		{
			printf("Not Anagram\n");
			return 0;
		}
	}
	if (t[i] == '\0')
	{
		printf("Anagram\n");
	}
}