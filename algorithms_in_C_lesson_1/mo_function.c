#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void init_array(int *pinakas, int n, int a, int b);
void print_array(int *pinakas, int n);
float mo_array(int *pinakas, int n);

main()
{
	int pinakas[SIZE];
	int i,sum,N=20;
	float mo;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..30 */
	
	init_array(pinakas,N,1,30);
	
	/* Ektypwsi tou pinaka */
	printf("Pinakas Dedomenwn: \n");
	print_array(pinakas,N);
	printf("\n\n");

	printf("\n\nO mesos oros einai: %.3f", mo_array(pinakas, N));
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

float mo_array(int *pinakas, int n)
{
	int i,sum;
	float mo;
	
	sum=0;
	for (i=0; i<n; i++)
	{
		sum+=pinakas[i];
	}
	
	mo=sum/(float)n;
	
	return mo;	
}
