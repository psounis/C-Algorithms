#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

void swap(int *a, int *b);
void quicksort(int *pinakas, int start, int finish, int *priorities);
int partition(int *pinakas, int start, int finish, int *priorities);
GRAPH BFSSpanningTreePriorities(GRAPH g, int start, int *priorities);

int main()
{
    GRAPH g, spanning_tree;
    int priorities[11] = {0, 8, 4, 9, 1, 3, 10, 2, 7, 5, 6};

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    spanning_tree = BFSSpanningTreePriorities(g, 4, priorities);
    printf("\n\nSpanning Tree\n");
    GR_print(spanning_tree);

    GR_destroy(g);
    GR_destroy(spanning_tree);

	return 0;
}

void swap(int *a, int *b)
{
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
}

void quicksort(int *pinakas, int start, int finish, int *priorities)
{
	int i,pos;
	if (start<finish)
	{
		pos=partition(pinakas,start,finish, priorities);
		quicksort(pinakas,start,pos-1, priorities);
		quicksort(pinakas,pos+1,finish, priorities);
	}
}

int partition(int *pinakas, int start, int finish, int *priorities)
{
	int pivot, i, j;

	pivot=pinakas[start];

	i=start+1;
	j=finish;

	while(1)
	{
		while(i<=finish && priorities[pinakas[i]]<=priorities[pivot])
		    i++;

		while(j>=start && priorities[pinakas[j]]>priorities[pivot])
			j--;

		if (i<j)
        {
            swap(&pinakas[i],&pinakas[j]);
		}
		else
		{
			swap(&pinakas[start],&pinakas[j]);
			return j;
		}
	}
}

GRAPH BFSSpanningTreePriorities(GRAPH g, int start, int *priorities)
{
	GRAPH st;
	QUEUE qu;
	int *discovered;
	int i, v, cnt, vertices, neighbors_length;
	int stop_loop, *neighbors;

    vertices = GR_vertices_count(g);
    GR_init(&st, vertices);

    discovered = (int *)malloc(sizeof(int)*vertices);
    if (!discovered)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    for (i=0; i<vertices; i++)
        discovered[i] = 0;

    QU_init(&qu);
    QU_enqueue(&qu, start);
    discovered[start]=1;
    cnt=1; stop_loop=FALSE;
    while(!QU_empty(qu)&&!stop_loop)
    {
        QU_dequeue(&qu, &v);
        GR_neighbors(g, v, &neighbors_length, &neighbors);
        quicksort(neighbors, 0, neighbors_length-1, priorities);
        for (i=0; i<neighbors_length; i++)
        {
            if (!discovered[neighbors[i]])
            {
                discovered[neighbors[i]]=1;
                QU_enqueue(&qu, neighbors[i]);
                GR_add_edge(st, v, neighbors[i]);
                cnt++;
                if (cnt==vertices)
                {
                    stop_loop=TRUE;
                    break;
                }
            }
        }
        free(neighbors);
    }
    QU_destroy(&qu);
	free(discovered);
	return st;
}
