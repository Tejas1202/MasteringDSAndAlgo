// Reversing a string
#include <stdio.h>
#include <string.h>

void reverse(char *s);
void reverse_two(char s[]);
void swap(char *a, char *b);

int main(void)
{
	char *s = "abcdefg";
	reverse(s);

	char str[] = "abcdefg";
	reverse_two(str);
	printf("%s\n", str);
}

// Reversing using auxiliary array as s is a string, so it's immutable
void reverse(char *s)
{
    int length = strlen(s);
    char reverse_s[length + 1];

    for (int i = 0, j = length - 1; i < length; i++, j--)
    {
        reverse_s[j] = s[i];
    }
    reverse_s[length] = '\0';
    printf("%s\n", reverse_s);
}

// Reversing directly on the original string using swapping
// Note: As this is a character array, hence its mutable, so we can perform swapping
// s will be a pointer to the caller variable as arrays are passed by address
void reverse_two(char s[])
{
    int j;
    for (j = 0; s[j] != '\0'; j++)
    {
    }

    for (int i = 0; i < j / 2; i++)
    {
        swap(&s[i], &s[j - i - 1]);
    }
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}