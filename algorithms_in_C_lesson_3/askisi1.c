#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

#define TRUE 1
#define FALSE 0

void init_array(double *pinakas, int n, int a, int b);
void print_array(double *pinakas, int n);
void swap(double *a, double *b);
void bubble_sort(double *pinakas, int n);
void quicksort(double *pinakas, int start, int finish);
int partition(double *pinakas, int start, int finish);

main()
{
	double pinakas[SIZE];
	int i,j,N=15;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..99 */
	
	init_array(pinakas,N,1,50);
	
	/* Ektypwsi tou pinaka kai tou stoixeiou*/
	printf("\t\t\tEPIDEIKSI BUBBLE SORT\n\n");
	printf("Arxi   : ");
	print_array(pinakas,N);

	/* Taksinomisi Pinaka */
	bubble_sort(pinakas, N);
	
	printf("\nTelos   : ");
	print_array(pinakas,N);	




	init_array(pinakas,N,1,50);	
	/* Ektypwsi tou pinaka kai tou stoixeiou*/
	printf("\t\t\tEPIDEIKSI QUICK SORT\n\n");
	printf("Arxi   : ");
	print_array(pinakas,N);

	/* Taksinomisi Pinaka */
	quicksort(pinakas, 0, N-1);
	
	printf("\nTelos   : ");
	print_array(pinakas,N);	


	
}

void init_array(double *pinakas, int n, int a, int b)
{
	int i;
	
	srand(time(NULL));
	
	for (i=0; i<n; i++)
		pinakas[i]=a+rand()%(b-a+1)+(rand()%100)/100.0;
}

void print_array(double *pinakas, int n)
{
	int i;
	
	printf("[");
	for (i=0; i<n-1; i++)
		printf("%2.2lf, ",pinakas[i]);
	printf("%2.2lf]",pinakas[n-1]);
}

void swap(double *a, double *b)
{
	double temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubble_sort(double *pinakas, int n)
{
	int i,j;

	for (i=0; i<n; i++)
	{
	   for (j=n-1; j>=i+1; j--)
	   {
	      if (pinakas[j]<pinakas[j-1])
	         swap(&pinakas[j], &pinakas[j-1]);
	   }
	}	
}

void quicksort(double *pinakas, int start, int finish)
{
	int i,pos;	
	if (start<finish)
	{				
		pos=partition(pinakas,start,finish);
		quicksort(pinakas,start,pos-1);
		quicksort(pinakas,pos+1,finish);
	}
}

int partition(double *pinakas, int start, int finish)
{
	double pivot;
	int i, j;
	

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

