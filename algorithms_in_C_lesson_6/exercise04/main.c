#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

GRAPH DAGShortestPaths(GRAPH g, int start, int *topological);

int main()
{
    GRAPH g, shortest_path_tree;
    int start=0;
    int topological[6] = {0,1,2,3,4,5};

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    shortest_path_tree = DAGShortestPaths(g, start, topological);

    printf("\nShortest Paths Tree: \n");
    GR_print(shortest_path_tree);

    GR_destroy(g);
    GR_destroy(shortest_path_tree);

	return 0;
}

GRAPH DAGShortestPaths(GRAPH g, int start, int *topological)
{
	int *B, *P;
	int i, x, v, cnt, vertices, neighbors_length;
	int infinity;
	elem *neighbors;
	GRAPH st;
	GRAPH g_reversed;

    vertices = GR_vertices_count(g);
    GR_init(&st, vertices);
    GR_init(&g_reversed, vertices);

    for (v=0; v<vertices; v++)
    {
        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (i=0; i<neighbors_length; i++)
            GR_add_edge(g_reversed, neighbors[i].id, v, neighbors[i].weight);
        free(neighbors);
    }
    printf("Reversed Graph: ");
    GR_print(g_reversed);

    /* B[*]: Mikos elaxistis diadromis gia na ftasoume stin korufi */
    B = (int *)malloc(sizeof(int)*vertices);
    if (!B)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    infinity = 0;
    for (v=0; v<vertices; v++)
    {
        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (i=0; i<neighbors_length; i++)
            infinity += neighbors[i].weight;
        free(neighbors);
    }
    for (i=0; i<vertices; i++)
        B[i] = infinity;
    B[start] = 0;


    /* P[*]: proigoymenos tis korifis sti veltisti diadromi */
    P = (int *)malloc(sizeof(int)*vertices);
    if (!P)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    for (i=0; i<vertices; i++)
        P[i] = -1;
    P[start] = start;

    /* Bellman-Ford */
    for (cnt=1; cnt<vertices; cnt++)
    {
        v=topological[cnt];
        GR_neighbors(g_reversed, v, &neighbors_length, &neighbors);
        for (x=0; x<neighbors_length; x++)
        {
            if (B[neighbors[x].id] + neighbors[x].weight < B[v])
            {
                B[v] = B[neighbors[x].id] + neighbors[x].weight;
                P[v] = neighbors[x].id;
            }
        }
        free(neighbors);

        /* Just for fun - some printing */
        printf("\nStep %d", cnt);
        printf("\nB:");
        for (i=0; i<vertices; i++)
            printf("%3d", B[i]);

        printf("\nP:");
        for (i=0; i<vertices; i++)
            printf("%3d", P[i]);
        printf("\n");
    }
    /* construct tree */
    for (i=1; i<vertices; i++)
        GR_add_edge(st, i, P[i], GR_edge_weight(g,P[i],i));


    free(B);
    free(P);

    return st;
}
