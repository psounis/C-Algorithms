#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void print_array(int *pinakas, int n);
void fibonacci(int *pinakas, int n);

main()
{
	int pinakas[SIZE];
	int i,N=20;

	/* Ypologismos twn arithmwn fibonacci */
	
	fibonacci(pinakas,N);	
	
	/* Ektypwsi tou pinaka */
	printf("Pinakas Dedomenwn: \n");
	print_array(pinakas,N);
	printf("\n\n");

}

void print_array(int *pinakas, int n)
{
	int i;
	
	printf("[");
	for (i=0; i<n-1; i++)
		printf("%d, ",pinakas[i]);
	printf("%d]",pinakas[n-1]);
}

void fibonacci(int *pinakas, int n)
{
	int i;
	
	pinakas[0]=1;
	pinakas[1]=1;
	for (i=2; i<n; i++)
	{
		pinakas[i]=pinakas[i-1]+pinakas[i-2];
	}
}
