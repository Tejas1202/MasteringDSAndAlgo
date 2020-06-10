// Creating 2D arrays with 3 different methods
#include <stdio.h>

int main(void) 
{
	// Whole 2D array created in stack
	int A[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	
	// Array of pointers
	int *B[3]; // Created in stack
	B[0] = (int *)malloc(4 * sizeof(int)); // In heap
	B[1] = (int *)malloc(4 * sizeof(int));
	B[2] = (int *)malloc(4 * sizeof(int));
	
	// Double pointers
	int **C;
	C = (int **)malloc(3 * sizeof(int *));
	C[0] = (int *)malloc(4 * sizeof(int));
	C[1] = (int *)malloc(4 * sizeof(int));
	C[2] = (int *)malloc(4 * sizeof(int));
	
	for(int i = 0; i <  3; i++)
    	{
        	for(int j = 0; j < 4; j++)
        	{
            		printf("%d ", C[i][j]);
        	}
        	printf("\n");
    	}
	return 0;
}