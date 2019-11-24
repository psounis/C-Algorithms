#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 100
#define COLS 100

main()
{
	int pinakas1[ROWS][COLS], pinakas2[ROWS][COLS], pinakas3[ROWS][COLS];
	int M=2, K=3, N=4;
	int i,j,k; 
	int a,b;
	
	/* Arxikopoiisi twn pinakwn */
	srand(time(NULL));
	a=0; b=2; 
	
	for (i=0; i<M; i++)
		for (j=0; j<K; j++)
			pinakas1[i][j]=a+rand()%(b-a+1);

	for (i=0; i<K; i++)
		for (j=0; j<N; j++)
			pinakas2[i][j]=a+rand()%(b-a+1);


	/* Ektypwsi twn arxikwn pinakwn */ 
	printf("Pinakas A:\n");
	for (i=0; i<M; i++)
	{
		for (j=0; j<K; j++)
			printf("%2d ", pinakas1[i][j]);
		printf("\n");
	}	

	printf("Pinakas B:\n");
	for (i=0; i<K; i++)
	{
		for (j=0; j<N; j++)
			printf("%2d ", pinakas2[i][j]);
		printf("\n");
	}	


	/* Ypologismos tou ginomenou */

	for (i=0; i<M; i++)
	{
	   for (j=0; j<N; j++)
	   {
	      pinakas3[i][j]=0;
		  
		  for (k=0; k<K; k++)
		  	pinakas3[i][j]+=pinakas1[i][k]*pinakas2[k][j];
	   }
	}


	/* Ektypwsi ginomenoy*/ 

	printf("Pinakas C:\n");
	for (i=0; i<M; i++)
	{
		for (j=0; j<N; j++)
			printf("%2d ", pinakas3[i][j]);
		printf("\n");
	}		
	
}


