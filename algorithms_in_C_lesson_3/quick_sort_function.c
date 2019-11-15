#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

#define TRUE 1
#define FALSE 0

int depth;

void init_array(int *pinakas, int n, int a, int b);
void print_array(int *pinakas, int n);
void swap(int *a, int *b);
void quicksort(int *pinakas, int start, int finish);
int partition(int *pinakas, int start, int finish);

main()
{
	int pinakas[SIZE];
	int i,j,pos,N=15;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..99 */
	
	init_array(pinakas,N,1,50);
	
	/* Ektypwsi tou pinaka kai tou stoixeiou*/
	printf("\t\t\tEPIDEIKSI QUICK SORT\n\n");
	printf("Arxi   : ");
	print_array(pinakas,N);

	/* Taksinomisi Pinaka */
	depth=0;
	printf("\n");
	quicksort(pinakas,0,N-1);
	printf("Telos   : ");
	print_array(pinakas,15);
	
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

void quicksort(int *pinakas, int start, int finish)
{
	int i,pos;	
	if (start<finish)
	{				
		pos=partition(pinakas,start,finish);
		quicksort(pinakas,start,pos-1);
		quicksort(pinakas,pos+1,finish);
	}
}

int partition(int *pinakas, int start, int finish)
{
	int pivot, i, j;
	

	pivot=pinakas[start];
	
	i=start+1;
	j=finish;
	
	while(1)
	{
		while(pinakas[i]<=pivot && i<=finish)
			i++;

		while(pinakas[j]>pivot && j>=start)
			j--;

		if (i<j)
			swap(&pinakas[i],&pinakas[j]);
		else
		{
			swap(&pinakas[start],&pinakas[j]);
			return j;
		}
			
	}

}
