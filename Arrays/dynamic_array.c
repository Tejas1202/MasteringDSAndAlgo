// Creating Dynamic arrays
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p,*q;
    p = (int *)malloc(3 * sizeof(int));
    p[0] = 2;
    p[1] = 4;
    p[2] = 6;
    q = (int *)malloc(6 * sizeof(int));
    
    for(int i = 0; i < 3; i++)
    {
        q[i] = p[i];
    }
    
    free(p);
    p = q;
    q = NULL;
    
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", p[i]);
    }
	return 0;
}