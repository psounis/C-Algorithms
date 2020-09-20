#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int negativeCycle(GRAPH g);

int main()
{
    GRAPH g;
    int hasCycle;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    hasCycle=negativeCycle(g);

    if (hasCycle)
        printf("There is a negative cycle");
    else
        printf("There are no negative cycles");

    GR_destroy(g);

	return 0;
}

int negativeCycle(GRAPH g)
{
	int *B, *Bnew, *P;
	int i, x, v, cnt, vertices, neighbors_length, result;
	int infinity, start = 0;
	elem *neighbors;

    vertices = GR_vertices_count(g);


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
        cnt++;

    }

    /* Another one step: */
    result = FALSE;
    for (i=0; i<vertices; i++)
    {
        GR_neighbors(g, i, &neighbors_length, &neighbors);
        for (x=0; x<neighbors_length; x++)
        {
            if (B[neighbors[x].id] + neighbors[x].weight < Bnew[i])
            {
                Bnew[i] = B[neighbors[x].id] + neighbors[x].weight;
                P[i] = neighbors[x].id;
                result=TRUE;
            }
        }
        free(neighbors);
    }


    free(B);
    free(Bnew);
    free(P);

    return result;
}
