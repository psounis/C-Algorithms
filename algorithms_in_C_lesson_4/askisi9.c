#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 100
#define COLS 100

main()
{
	int pinakas[ROWS][COLS], sums[COLS];
	int M=4, N=6;
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
	for (j=0; j<N; j++)
	{
	   sums[j]=0; 
	   for (i=0; i<M; i++)
	   {
	      sums[j]+=pinakas[i][j]; 
	   }
	}


	
	/* Ektypwsi tvn athroismatwn */ 
	printf("\n");
	for (j=0; j<N; j++)
	{
	   printf("%2d ", sums[j]);
	}

	
}


