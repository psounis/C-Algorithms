#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

#define TRUE 1
#define FALSE 0

void init_array(int *pinakas, int n, int a, int b);
void print_array(int *pinakas, int n);
void swap(int *a, int *b);
void selection_sort(int *pinakas, int n);

main()
{
	int pinakas[SIZE];
	int i,j,pos,N=15;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..99 */
	
	init_array(pinakas,N,1,50);
	
	/* Ektypwsi tou pinaka kai tou stoixeiou*/
	printf("\t\t\tEPIDEIKSI SELECTION SORT\n\n");
	printf("Arxi   : ");
	print_array(pinakas,N);

	/* Taksinomisi Pinaka */
	selection_sort(pinakas, N);
	
	printf("\n\nTelos   : ");
	print_array(pinakas,N);
	
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
		printf("%2d, ",pinakas[i]);
	printf("%2d]",pinakas[n-1]);
}

void swap(int *a, int *b)
{
	int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
}

void selection_sort(int *pinakas, int n)
{
	int i,j,pos;
	
	for (i=0; i<n; i++)
	{
		pos=i;
	
		for (j=i+1; j<n; j++)
		{
			if (pinakas[j]<pinakas[pos])
				pos=j;
		}
	
		swap(&pinakas[i], &pinakas[pos]);
	}	
}
