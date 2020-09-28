/* graph.c: Kwdikas tis vivliothikis grafoy (pin.geitniasis) */
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "linked_list.h"

/* GR_init(): arxikopoiei to grafo */
void GR_init(GRAPH *g, int N)
{
	int i;
	g->N = N;

	g->array = (LIST_PTR *)malloc(sizeof(LIST_PTR)*N);
	if(!g->array)
	{
		printf("Error Allocating Memory");
		exit(0);
	}
	for (i=0; i<N; i++)
		LL_init(&(g->array[i]));

}

/* GR_print(): ektypwnei to grafo */
void GR_print(GRAPH g)
{
	int i;

	for (i=0; i<g.N; i++)
	{
		printf("%2d: ", i);
		LL_print(g.array[i]);
		printf("\n");
	}
}

/* GR_add_edge(): prosthiki akmis */
void GR_add_edge(GRAPH g, int vertex1, int vertex2, int weight)
{
	if (vertex1<0 || vertex1>g.N || vertex2<0 || vertex2>g.N)
	{
		printf("Error: index out of bounds");
		exit(0);
	}

	LL_insert(&g.array[vertex1], vertex2, weight);
	LL_insert(&g.array[vertex2], vertex1, weight);
}

int GR_remove_edge(GRAPH g, int vertex1, int vertex2)
{
    int res1, res2;
	if (vertex1<0 || vertex1>g.N || vertex2<0 || vertex2>g.N)
	{
		printf("Error: index out of bounds");
		exit(0);
	}

    res1=LL_delete(&(g.array[vertex1]), vertex2);
    res2=LL_delete(&(g.array[vertex2]), vertex1);
    return res1&&res2;
}
void GR_destroy(GRAPH g)
{
    int i;

    for (i=0; i<g.N; i++)
    {
        LL_destroy(&g.array[i]);
    }

    free(g.array);
}

int GR_vertices_count(GRAPH g)
{
    return g.N;
}

int GR_edges_count(GRAPH g)
{
    int i, cnt, neighbors_length;
    elem *neighbors;

    cnt = 0;
    for (i=0; i<g.N; i++)
    {
        GR_neighbors(g, i, &neighbors_length, &neighbors);
        cnt+=neighbors_length;
        free(neighbors);
    }
    return cnt/2;
}

int GR_edge_weight(GRAPH g, int vertex1, int vertex2)
{
	LIST_PTR current;

	current=g.array[vertex1];
	while(current!=NULL)
	{
		if (current->data.id==vertex2)
            return current->data.weight;
		current=current->next;
	}
	return 0;
}


/* GR_init_from_file(): arxikopoiisi apo arxeio */
void GR_init_from_file(GRAPH *g, char *filename)
{
	int i,j,w;
	FILE *fp;

	fp = fopen(filename, "r");
	if (!fp)
	{
		printf("Error opening file");
		exit(0);
	}
	fscanf(fp,"%d", &g->N);

	g->array = (LIST_PTR *)malloc(sizeof(LIST_PTR)*g->N);
	if(!g->array)
	{
		printf("Error Allocating Memory");
		exit(0);
	}

	for (i=0; i<g->N; i++)
		LL_init(&(g->array[i]));

	while(!feof(fp))
	{
		fscanf(fp,"%d %d %d", &i, &j, &w);
		GR_add_edge(*g, i, j, w);
	}

	fclose(fp);
}

void GR_neighbors(GRAPH g, int vertex, int *length, elem **elements)
{
    LL_to_array(g.array[vertex], length, elements);
}
