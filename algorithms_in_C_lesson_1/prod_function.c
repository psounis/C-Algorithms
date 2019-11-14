#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void init_array(int *pinakas, int n, int a, int b);
void print_array(int *pinakas, int n);
int prod_array(int *pinakas, int n);

main()
{
	int pinakas[SIZE];
	int i,prod,N=20;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..5 */
	
	init_array(pinakas,N,1,5);
	
	/* Ektypwsi tou pinaka */
	printf("Pinakas Dedomenwn: \n");
	print_array(pinakas,N);
	printf("\n\n");

	printf("\n\nTo ginomeno einai: %d", prod_array(pinakas,N));
	
}




void init_array(int *pinakas, int n, int a, int b)
{
	int i;
	
	srand(time(NULL));
	
	for (i=0; i<n; i++)
		pinakas[i]=a+rand()%(b-a+1);
}

void print_array(int *pinakas, int n)
{
	int i;
	
	printf("[");
	for (i=0; i<n-1; i++)
		printf("%d, ",pinakas[i]);
	printf("%d]",pinakas[n-1]);
}

int prod_array(int *pinakas, int n)
{
	int prod;
	int i;
	
	prod=1;
	for (i=0; i<n; i++)
	{
		prod*=pinakas[i];
	}
	
	return prod;
}

