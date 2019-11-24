#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 100
#define COLS 100

main()
{
	int pinakas[ROWS][COLS];
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

	/* Ektypwsi toy arxikoy pinaka */ 
	printf("Stiles Pinaka (antistrofws):\n");
	for (j=0; j<N; j++)
	{
		for (i=M-1; i>=0; i--)
			printf("%2d ", pinakas[i][j]);
		printf("\n");
	}	

	
}


