#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE1 100
#define SIZE2 200

#define TRUE 1
#define FALSE 0

void init_array(int **pinakas, int m, int n, int a, int b);

main()
{
	int pinakas[SIZE1][SIZE2];
	int M=10,N=20,i,j;
	
	/* Arxikopoiisi tou pinaka */
	init_array(pinakas,M,N,1,50);
	
	/* Ektypwsi twn pinakwn */
	printf("\t\t\tEPIDEIKSI EKTYPWSIS PINAKWN\n\n");

	for (i=0; i<M; i++)
	{
		for (j=0; j<N; j++)
			printf("%3d",pinakas[i][j]);
		printf("\n");
	}
	
}

void init_array(int **pinakas, int m, int n, int a, int b)
{
	int i,j;
	
	srand(time(NULL));
	
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			pinakas[i][j]=a+rand()%(b-a+1);
}


