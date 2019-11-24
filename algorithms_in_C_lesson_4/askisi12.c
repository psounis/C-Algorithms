#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_array(int ***pinakas, int m, int n);
void init_array(int **pinakas, int m, int n, int a, int b);
void sum_array(int **pinakas3, int **pinakas1, int **pinakas2, int m, int n);
void print_array(int **pinakas, int m, int n);
void destroy_array(int **pinakas, int m, int n);

main()
{
	int **pinakas1, **pinakas2, **pinakas3;
	int M=4, N=6;
	int i,j; 
	int a,b;
	
	/* Dimiourgia twn pinaka */
	create_array(&pinakas1, M, N);
	create_array(&pinakas2, M, N);
	create_array(&pinakas3, M, N);
	
	/* Arxikopoiisi twn pinakwn */
	srand(time(NULL));
	a=4; b=5;
	init_array(pinakas1, M, N, a, b);
	init_array(pinakas2, M, N, a, b);


	/* Ektypwsi toy arxikoy pinaka */ 
	printf("Pinakas A:\n");
	print_array(pinakas1, M, N);	

	printf("Pinakas B:\n");
	print_array(pinakas2, M, N);		


	/* Ypologismos tou athroismatos */

	sum_array(pinakas3, pinakas1, pinakas2, M, N);


	/* Ektypwsi athroismatos*/ 

	printf("Pinakas C:\n");
	print_array(pinakas3, M, N);
	
	/* Apodesmeusi Mnimis */
	destroy_array(pinakas1, M, N);
	destroy_array(pinakas2, M, N);
	destroy_array(pinakas3, M, N);
	
}

void create_array(int ***pinakas, int m, int n)
{
	int i; 
	
	(*pinakas) = (int **)malloc(sizeof(int *)*m);
	if (!(*pinakas))
	{
		printf("Error allocating memory!");
		exit(0);
	}
	
	for (i=0; i<n; i++)
	{
		(*pinakas)[i]=(int *)malloc(sizeof(int)*n);
		if (!(*pinakas)[i])
		{
			printf("Error Allocating Memory!");
			exit(0);
			
		}
	}
}

void init_array(int **pinakas, int m, int n, int a, int b)
{
	int i,j; 
	
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			pinakas[i][j]=a+rand()%(b-a+1);	
}

void sum_array(int **pinakas3, int **pinakas1, int **pinakas2, int m, int n)
{
	int i,j;
	
	for (i=0; i<m; i++)
	{
	   for (j=0; j<n; j++)
	   {
	      pinakas3[i][j]=pinakas1[i][j]+pinakas2[i][j];
	   }
	}
}

void print_array(int **pinakas, int m, int n)
{
	int i, j; 
	
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
			printf("%2d ", pinakas[i][j]);
		printf("\n");
	}		
}

void destroy_array(int **pinakas, int m, int n)
{
	int i; 
	
	for (i=0; i<m; i++)
		free(pinakas[i]);
	free(pinakas);
}
