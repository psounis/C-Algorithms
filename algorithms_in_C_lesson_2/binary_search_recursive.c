#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

#define TRUE 1
#define FALSE 0

void init_sorted_array(int *pinakas, int n, int a, int max_step);
void print_array(int *pinakas, int n);
void print_partial_array(int *pinakas, int start, int finish, int n);
int binary_search_rec(int *pinakas, int start, int finish, int x);


main()
{
	int pinakas[SIZE];
	int i,x,start,finish,middle,found,N=19;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..20 
	   kai tou stoixeiou x*/
	
	init_sorted_array(pinakas,N,1,2);
	x=1+rand()%30;
	
	/* Ektypwsi tou pinaka kai tou stoixeiou*/
	printf("Pinakas Dedomenwn: \n");
	print_array(pinakas,N);
	printf("\nStoixeio x=%d",x);
	printf("\n\n");

	found=binary_search_rec(pinakas,0,N-1,x);
	
	if (found)
		printf("To stoixeio vrethike!");
	else 
		printf("To stoixeio DEN vrethike!");
}




void init_sorted_array(int *pinakas, int n, int a, int max_step)
{
	int i;
	
	srand(time(NULL));
	
	pinakas[0]=a;
	for (i=1; i<n; i++)
		pinakas[i]=pinakas[i-1]+rand()%max_step+1;
}

void print_array(int *pinakas, int n)
{
	int i;
	
	printf("[");
	for (i=0; i<n-1; i++)
		printf("%2d,",pinakas[i]);
	printf("%2d]",pinakas[n-1]);
}


void print_partial_array(int *pinakas, int start, int finish, int n)
{
	int i;
	
	printf("[");
	for (i=0; i<start; i++)
		printf("   ",pinakas[i]);
	for (i=start; i<finish; i++)
		printf("%2d,",pinakas[i]);
	for (i=finish; i<n-1; i++)
		printf("   ",pinakas[i]);
	
	if (finish==n-1)
		printf("%2d]\n",pinakas[n-1]);
	else
		printf("  ]\n");
}

int binary_search_rec(int *pinakas, int start, int finish, int x)
{
	int middle;
	
	if (start>finish)
		return FALSE;
	else
	{
		middle=(start+finish)/2;
		if (x==pinakas[middle])
			return TRUE;
		else if (x<pinakas[middle])
			return binary_search_rec(pinakas,start,middle-1,x);
		else 
			return binary_search_rec(pinakas,middle+1,finish,x);
	}
}

