#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

GRAPH BellmanShortestPathTree(GRAPH g, int start);

int main()
{
    GRAPH g, shortest_path_tree;
    int start=0;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    shortest_path_tree = BellmanShortestPathTree(g, start);

    printf("\nShortest Paths Tree: \n");
    GR_print(shortest_path_tree);

    GR_destroy(g);
    GR_destroy(shortest_path_tree);

	return 0;
}

GRAPH BellmanShortestPathTree(GRAPH g, int start)
{
	int *B, *Bnew, *P;
	int i, x, v, cnt, vertices, neighbors_length;
	int infinity;
	elem *neighbors;
	GRAPH st;

    vertices = GR_vertices_count(g);
    GR_init(&st, vertices);

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

    /* Bnew[i]=0 an i korufi den exei oristikopoiithei, alliws 1 */
    Bnew = (int *)malloc(sizeof(int)*vertices);
    if (!Bnew)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }


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
    cnt=1;
    for (i=0; i<vertices; i++) Bnew[i]=B[i];
    while(cnt<vertices)
    {
        for (i=0; i<vertices; i++)
        {
            GR_neighbors(g, i, &neighbors_length, &neighbors);
            for (x=0; x<neighbors_length; x++)
            {
                if (B[neighbors[x].id] + neighbors[x].weight < Bnew[i])
                {
                    Bnew[i] = B[neighbors[x].id] + neighbors[x].weight;
                    P[i] = neighbors[x].id;
                }
            }
            free(neighbors);
        }
        for (i=0; i<vertices; i++) B[i]=Bnew[i];


        /* Just for fun - some printing */
        printf("\nStep %d", cnt);
        printf("\nB: ");
        for (i=0; i<vertices; i++)
            printf("%3d", B[i]);

        printf("\nP: ");
        for (i=0; i<vertices; i++)
            printf("%3d", P[i]);
        printf("\n");

        cnt++;
    }
    /* construct tree */
    for (i=1; i<vertices; i++)
        GR_add_edge(st, i, P[i], GR_edge_weight(g,i,P[i]));


    free(B);
    free(Bnew);
    free(P);

    return st;
}
