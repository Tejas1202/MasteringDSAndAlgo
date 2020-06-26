// Comparing two strings for equality
#include <stdio.h>

int main(void)
{
	char *s = "Hawking";
	char *t = "Hawking";

	int i = 0, j = 0;
	for(; s[i] != '\0' && t[j] != '\0'; i++, j++)
	{
	    if (s[i] != t[j])
	    {
	    	printf("Not equal\n");
	    	return 0;
	    }
	}
	if (s[i] == t[j])
	{
		printf("Equal\n");
	}
	else
	{
		printf("Not equal\n");
	}
}