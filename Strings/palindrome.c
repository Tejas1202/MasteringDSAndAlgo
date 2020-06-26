// Check whether string is a palindrome
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "madam";
	int length = strlen(s);
	for (int i = 0, j = length - 1; i < j / 2; i++)
	{
		if (s[i] != s[j - i])
		{
			printf("Not a palindrome\n");
			return 0;
		}
	}
	printf("Palindrome\n");
}