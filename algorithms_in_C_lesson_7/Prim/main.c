#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

GRAPH Prim(GRAPH g);

int main()
{
    GRAPH g, spanning_tree;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    spanning_tree = Prim(g);

    printf("\nSpanning Tree: \n");
    GR_print(spanning_tree);

    GR_destroy(g);
    GR_destroy(spanning_tree);

	return 0;
}

GRAPH Prim(GRAPH g)
{
    struct edge {
        int vertex1;
        int vertex2;
    };
    struct edge *E;
	int *Q, *C;
	int i, x, v, cnt, vertices, neighbors_length;
	int min, infinity;
	int start = 0;
	elem *neighbors;
	GRAPH st;

    vertices = GR_vertices_count(g);
    GR_init(&st, vertices);

    /* C[*]: Varos elaxistis akmis tis korifis v */
    C = (int *)malloc(sizeof(int)*vertices);
    if (!C)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    infinity = 0;
    for (v=0; v<vertices; v++)
    {
        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (i=0; i<neighbors_length; i++)
            if (infinity < neighbors[i].weight)
                infinity = neighbors[i].weight;
        free(neighbors);
    }
    infinity = infinity + 1;
    for (i=0; i<vertices; i++)
        C[i] = infinity;
    C[start] = 0;

    /* E[*]: kaliteri akmi gia na sindethei o komvos v */
    E = (struct edge *)malloc(sizeof(struct edge)*vertices);
    if (!E)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }

    /* Q[i]=0 an i korufi den exei oristikopoiithei, alliws 1 */
    Q = (int *)malloc(sizeof(int)*vertices);
    if (!Q)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    for (i=0; i<vertices; i++)
        Q[i] = 0;

    /* Prim */
    GR_neighbors(g, start, &neighbors_length, &neighbors);
    for (x=0; x<neighbors_length; x++)
    {
        C[neighbors[x].id] = neighbors[x].weight;
        E[neighbors[x].id].vertex1 = start;
        E[neighbors[x].id].vertex2 = neighbors[x].id;
    }
    free(neighbors);
    Q[start]=1;

    cnt=1;
    while(cnt<vertices)
    {
        min=infinity;
        for (i=0; i<vertices; i++)
            if (C[i]<min && Q[i]==0)
            {
                min = C[i];
                v=i;
            }
        cnt++;
        Q[v]=1;
        GR_add_edge(st, E[v].vertex1, E[v].vertex2, C[v]);
        printf("\nProstithetai: (%d, %d) me varos %d", E[v].vertex1, E[v].vertex2, C[v]);

        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (x=0; x<neighbors_length; x++)
        {
            if (Q[neighbors[x].id]==0 && neighbors[x].weight<C[neighbors[x].id])
            {
                C[neighbors[x].id] = neighbors[x].weight;
                E[neighbors[x].id].vertex1 = v;
                E[neighbors[x].id].vertex2 = neighbors[x].id;
            }
        }
        free(neighbors);
    }

    free(C);
    free(E);
    free(Q);

    return st;
}
