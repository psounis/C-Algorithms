#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "disjoint_sets.h"

struct edge {
    int vertex1;
    int vertex2;
    int weight;
};
typedef struct edge EDGE;

GRAPH Kruskal(GRAPH g);
void swap(EDGE *a, EDGE *b);
void quicksort(EDGE *pinakas, int start, int finish);
int partition(EDGE *pinakas, int start, int finish);

int main()
{
    GRAPH g, spanning_tree;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    spanning_tree = Kruskal(g);

    printf("\n\nSpanning Tree: \n");
    GR_print(spanning_tree);

    GR_destroy(g);
    GR_destroy(spanning_tree);

	return 0;
}

GRAPH Kruskal(GRAPH g)
{
    struct edge *sorted_edges;
    int edge_count;
	int i, x, v, cnt, vertices, neighbors_length;
	elem *neighbors;
	GRAPH st;
	DISJOINT d;

    vertices = GR_vertices_count(g);
    GR_init(&st, vertices);
    DS_init(&d, vertices);

    /* Sort Edges */
    edge_count = GR_edges_count(g);
    sorted_edges = (struct edge *)malloc(sizeof(struct edge)*edge_count);
    if(!sorted_edges)
    {
        printf("Error Allocating Memory");
        exit(0);
    }
    i=0;
    for (v=0; v<vertices; v++)
    {
        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (x=0; x<neighbors_length; x++)
        {
            if (v<neighbors[x].id)
            {
                sorted_edges[i].vertex1=v;
                sorted_edges[i].vertex2=neighbors[x].id;
                sorted_edges[i].weight=neighbors[x].weight;
                i++;
            }
        }
    }
    quicksort(sorted_edges, 0, edge_count-1);

    /* Kruskal */
    printf("\nRunning:");
    i=0; cnt=0;
    while(cnt<vertices-1)
    {
        if (DS_find_set(d,sorted_edges[i].vertex1)!=DS_find_set(d,sorted_edges[i].vertex2))
        {
            printf("\nProstithetai: (%d, %d) me varos %d", sorted_edges[i].vertex1, sorted_edges[i].vertex2, sorted_edges[i].weight);
            GR_add_edge(st, sorted_edges[i].vertex1, sorted_edges[i].vertex2, sorted_edges[i].weight);
            DS_union(&d, sorted_edges[i].vertex1, sorted_edges[i].vertex2);
            cnt++;
        }
        else
            printf("\nAporriptetai: (%d, %d) me varos %d", sorted_edges[i].vertex1, sorted_edges[i].vertex2, sorted_edges[i].weight);

        i++;
    }

    free(sorted_edges);
    DS_destroy(&d);
    return st;
}


void swap(EDGE *a, EDGE *b)
{
	EDGE temp;

	temp=*a;
	*a=*b;
	*b=temp;
}

void quicksort(EDGE *pinakas, int start, int finish)
{
	int pos;
	if (start<finish)
	{
		pos=partition(pinakas,start,finish);
		quicksort(pinakas,start,pos-1);
		quicksort(pinakas,pos+1,finish);
	}
}

int partition(EDGE *pinakas, int start, int finish)
{
	int pivot, i, j;

	pivot=pinakas[start].weight;

	i=start+1;
	j=finish;

	while(1)
	{
		while(i<=finish && pinakas[i].weight<=pivot)
		    i++;

		while(j>=start && pinakas[j].weight>pivot)
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
