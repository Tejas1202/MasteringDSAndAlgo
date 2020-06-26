// Permutations of a string using Swapping
#include <stdio.h>
#include <string.h>

void perm(char *s, int l, int h);
void swap(char *a, char *b);

int main(void)
{
    // As strings are immutable, therefore taking char array instead of char *
	char s[] = "ABC";
	int length = strlen(s);
	perm(s, 0, length - 1);
}

void perm(char s[], int l, int h)
{
   if (l == h)
   {
       printf("%s\n", s);
   }
   else
   {
       for (int i = l; i <= h; i++)
       {
           swap(&s[l], &s[i]);
           perm(s, l + 1, h);
           swap(&s[l], &s[i]);
       }
   }
}

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}