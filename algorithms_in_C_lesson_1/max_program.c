#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void init_array(int *pinakas, int n, int a, int b);
void print_array(int *pinakas, int n);

main()
{
	int pinakas[SIZE];
	int i,max,N=20;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..30 */
	
	init_array(pinakas,N,1,100);
	
	/* Ektypwsi tou pinaka */
	printf("Pinakas Dedomenwn: \n");
	print_array(pinakas,N);
	printf("\n\n");

	/* Ypologismos tou megistou */
	max=pinakas[0];
	printf("\n\n \ti\tpin[i]\tmax\n");
	printf("-----------------------------\n");
	printf(">\t%d\t%d\t%d\n",0,pinakas[0],max);
	
	for (i=1; i<N; i++)
	{
		if (pinakas[i]>max)
		{
			max=pinakas[i];
			printf(">");
		}
			
		printf("\t%d\t%d\t%d\n",i,pinakas[i],max);
	}
	
	printf("\n\nO megistos einai: %d", max);
	
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
		printf("%d, ",pinakas[i]);
	printf("%d]",pinakas[n-1]);
}

