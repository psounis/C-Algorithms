#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void init_array(int *pinakas, int n, int a, int b);
void print_array(int *pinakas, int n);
int cnt_array(int *pinakas, int n, int x);

main()
{
	int pinakas[SIZE];
	int i,sum,N=20,x;
	
	/* Arxikopoiisi enos pinaka 20 thesewn 
	   me tyxaious arithmous sto 1..30 */
	
	init_array(pinakas,N,1,10);
	x=1+rand()%10;
	
	/* Ektypwsi tou pinaka */
	printf("Pinakas Dedomenwn: \n");
	print_array(pinakas,N);
	printf("\n\n");

	
	printf("\n\nTo plithos twn emfanisewn toy %d einai: %d", x, cnt_array(pinakas,N,x));
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

int cnt_array(int *pinakas, int n, int x)
{
	int i, cnt;
	
	cnt=0;
	for (i=0; i<n; i++)
	{
		if (pinakas[i]==x)
			cnt++;
	}
	
	return cnt;
}
