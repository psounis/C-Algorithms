#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void init_array(int *pinakas, int n, int a, int b);
void print_array(int *pinakas, int n);

main()
{
	int pinakas[SIZE];
	int i,min,N=20;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..30 */
	
	init_array(pinakas,N,1,100);
	
	/* Ektypwsi tou pinaka */
	printf("Pinakas Dedomenwn: \n");
	print_array(pinakas,N);
	printf("\n\n");

	/* Ypologismos tou elaxistou */
	min=pinakas[0];
	printf("\n\n \ti\tpin[i]\tmin\n");
	printf("-----------------------------\n");
	printf(">\t%d\t%d\t%d\n",0,pinakas[0],min);
	
	for (i=1; i<N; i++)
	{
		if (pinakas[i]<min)
		{
			min=pinakas[i];
			printf(">");
		}
			
		printf("\t%d\t%d\t%d\n",i,pinakas[i],min);
	}
	
	printf("\n\nO elaxistos einai: %d", min);
	
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

