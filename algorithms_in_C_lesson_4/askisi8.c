#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 100
#define COLS 100

main()
{
	int pinakas[ROWS][COLS], sums[ROWS];
	int M=10, N=15;
	int i,j; 
	int a,b;
	
	/* Arxikopoiisi tou pinaka */
	srand(time(NULL));
	a=5; b=10; 
	
	for (i=0; i<M; i++)
		for (j=0; j<N; j++)
			pinakas[i][j]=a+rand()%(b-a+1);

	/* Ektypwsi toy arxikoy pinaka */ 
	printf("Pinakas:\n");
	for (i=0; i<M; i++)
	{
		for (j=0; j<N; j++)
			printf("%2d ", pinakas[i][j]);
		printf("\n");
	}	


	/* Ypologismos twn athroismatwn */
	for (i=0; i<M; i++)
	{
	   sums[i]=0; 
	   for (j=0; j<N; j++)
	   {
	      sums[i]+=pinakas[i][j]; 
	   }
	}


	
	/* Ektypwsi tvn athroismatwn */ 
	printf("\n");
	for (i=0; i<M; i++)
	{
	   printf("%2d ", sums[i]);
	}

	
}


