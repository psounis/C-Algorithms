#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 100
#define COLS 100

main()
{
	int pinakas1[ROWS][COLS], pinakas2[ROWS][COLS];
	int M=2, N=4;
	int i,j; 
	int a,b;
	
	/* Arxikopoiisi twn pinakwn */
	srand(time(NULL));
	a=0; b=2; 
	
	for (i=0; i<M; i++)
		for (j=0; j<N; j++)
			pinakas1[i][j]=a+rand()%(b-a+1);


	/* Ektypwsi twn arxikwn pinakwn */ 
	printf("Pinakas A:\n");
	for (i=0; i<M; i++)
	{
		for (j=0; j<N; j++)
			printf("%2d ", pinakas1[i][j]);
		printf("\n");
	}	


	/* Ypologismos tou anastrofou */

	for (i=0; i<M; i++)
	{
	   for (j=0; j<N; j++)
	   {
	      pinakas2[j][i]=pinakas1[i][j];
	   }
	}


	/* Ektypwsi anastrofou*/ 

	printf("Pinakas anastrofos:\n");
	for (i=0; i<N; i++)
	{
		for (j=0; j<M; j++)
			printf("%2d ", pinakas2[i][j]);
		printf("\n");
	}		
	
}


