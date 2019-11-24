#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 100
#define COLS 100

main()
{
	int pinakas[ROWS][COLS], sum_row[ROWS], sum_col[COLS];
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

	/* grammes */ 
	for (i=0; i<M; i++)
	{
	   sum_row[i]=0; 
	   for (j=0; j<N; j++)
	   {
	      sum_row[i]+=pinakas[i][j]; 
	   }
	}

	/* stiles */ 
	for (j=0; j<N; j++)
	{
	   sum_col[j]=0; 
	   for (i=0; i<M; i++)
	   {
	      sum_col[j]+=pinakas[i][j]; 
	   }
	}

	/* Teliki ektypwsi */ 
	printf("\n\nPinakas me athroismata:\n");
	for (i=0; i<M; i++)
	{
		for (j=0; j<N; j++)
			printf("%2d ", pinakas[i][j]);
		printf("  %2d", sum_row[i]);
		printf("\n");
	}	
	
	/* Ektypwsi tvn athroismatwn */ 
	printf("\n");
	for (j=0; j<N; j++)
	{
	   printf("%2d ", sum_col[j]);
	}

	
}


