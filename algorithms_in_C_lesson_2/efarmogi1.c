#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

#define TRUE 1
#define FALSE 0

void init_array(int *pinakas, int n, int a, int b);
void print_array(int *pinakas, int n);
int linear_search_pos(int *pinakas, int n, int x);

main()
{
	int pinakas[SIZE];
	int i,x,position,N=20;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..20 
	   kai tou stoixeiou x*/
	
	init_array(pinakas,N,1,20);
	x=1+rand()%20;
	
	/* Ektypwsi tou pinaka kai tou stoixeiou*/
	printf("Pinakas Dedomenwn: \n");
	print_array(pinakas,N);
	printf("\nStoixeio x=%d",x);
	printf("\n\n");

	/* Anazitisi tou stoixeiou */
	
	position=linear_search_pos(pinakas,N,x);
	
	if (position>=0)
		printf("To stoixeio vrethike sti thesi %d!", position);
	else 
		printf("To stoixeio DEN vrethike!");
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

int linear_search_pos(int *pinakas, int n, int x)
{
	int i;
	
	for (i=0; i<n; i++)
	{
		if (x==pinakas[i])
		{
			return i;
		}	
	}	
	return -1;
}

