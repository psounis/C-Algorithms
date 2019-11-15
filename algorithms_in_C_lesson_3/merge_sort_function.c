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
void mergesort(int *pinakas, int start, int finish);
void merge(int *pinakas, int start, int finish);

main()
{
	int pinakas[SIZE];
	int i,j,pos,N=15;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..99 */
	
	init_array(pinakas,N,1,50);
	
	/* Ektypwsi tou pinaka kai tou stoixeiou*/
	printf("\t\t\tEPIDEIKSI MERGE SORT\n\n");
	printf("Arxi   : ");
	print_array(pinakas,N);

	/* Taksinomisi Pinaka */
	depth=0;
	printf("\n");
	mergesort(pinakas,0,N-1);
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

void mergesort(int *pinakas, int start, int finish)
{
	int i,middle;
	
	if (start==finish) /* 1 stoixeio */
		return;
	else if (start==finish-1) /* 2 stoixeia */
	{
		if (pinakas[start]>pinakas[finish])
			swap(&pinakas[start], &pinakas[finish]);
	}
	else
	{
		middle=(start+finish)/2;
		mergesort(pinakas,start,middle);
		mergesort(pinakas,middle+1,finish);
		merge(pinakas,start,finish);
	}
}

void merge(int *pinakas, int start, int finish)
{
	int C[SIZE];
	int i,j,k;
	int middle, n, m;
	
	middle=(start+finish)/2;
	
	/* 1os pinakas PIN[start..middle]=PIN[i..n] */	
	i=start;
	n=middle;
	/* 2os pinakas PIN[middle+1..finish]=PIN[j...m] */	
	j=middle+1;
	m=finish;
	/* C: sigxwneumenos pinakas */	
	k=0;
	
	/* 1. Sigxwneusi twn dio pinakwn */
	while (i<=n && j<=m)
	{
		if (pinakas[i]<pinakas[j])
		{
			C[k]=pinakas[i];
			k++;
			i++;
		}
		else
		{
			C[k]=pinakas[j];
			k++;
			j++;
		}
	}
	
	/* 2. Antigrafi tou pinaka pou perissevei sto telos tou sigxwneumenou pinaka */
	
	if (i==n+1) /* Eksantlithike o 1os pinakas */
	{
		while (j<=m)
		{
			C[k]=pinakas[j];
			k++;
			j++;
		}
	}
	else /* Eksantlithike o 2os pinakas */
	{
		while (i<=n)
		{
			C[k]=pinakas[i];
			k++;
			i++;
		}
	}	
	
	/* 3. Antigrafi tou C ston pinakas */
	
	k=0;
	
	i=start;
	while (i<=finish)
	{
		pinakas[i]=C[k];
		i++;
		k++;
	}
}
