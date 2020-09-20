#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

GRAPH DijkstraShortestPathTree(GRAPH g, int start);

int main()
{
    GRAPH g, shortest_path_tree;
    int start=0;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    shortest_path_tree = DijkstraShortestPathTree(g, start);

    printf("\nShortest Paths Tree: \n");
    GR_print(shortest_path_tree);

    GR_destroy(g);
    GR_destroy(shortest_path_tree);

	return 0;
}

GRAPH DijkstraShortestPathTree(GRAPH g, int start)
{
	int *Q, *L, *P;
	int i, x, v, cnt, vertices, neighbors_length;
	int infinity, min;
	int path_size, *shortest_path;
	elem *neighbors;
	GRAPH st;

    vertices = GR_vertices_count(g);
    GR_init(&st, vertices);

    /* L[*]: Mikos elaxistis diadromis gia na ftasoume stin korufi */
    L = (int *)malloc(sizeof(int)*vertices);
    if (!L)
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
        L[i] = infinity;
    L[start] = 0;

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

    /* Q[i]=0 an i korufi den exei oristikopoiithei, alliws 1 */
    Q = (int *)malloc(sizeof(int)*vertices);
    if (!Q)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    for (i=0; i<vertices; i++)
        Q[i] = 0;

    /* Dijkstra */
    printf("\nShortest Paths: ");
    cnt=0;
    while(cnt<vertices)
    {
        min=infinity;
        for (i=0; i<vertices; i++)
            if (L[i]<min && Q[i]==0)
            {
                min = L[i];
                v=i;
            }
        cnt++;
        Q[v]=1;

        if (cnt>=2)
        {
            GR_add_edge(st, P[v], v, GR_edge_weight(g,P[v],v));

            path_size = 2;
            i = v;
            while(P[i]!=start)
            {
                i = P[i];
                path_size++;
            }
            shortest_path = (int *)malloc(sizeof(int)*path_size);
            if (!shortest_path)
            {
                printf("Error Allocating Memory!");
                exit(0);
            }
            x = v;
            for (i=path_size-1; i>=0; i--)
            {
                shortest_path[i] = x;
                x = P[x];
            }

            printf("\nFrom %d to %d: ", start, v);
            for (i=0; i<path_size; i++)
                printf("%d ", shortest_path[i]);
            printf(" [length: %d]", L[v]);
            free(shortest_path);
        }

        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (x=0; x<neighbors_length; x++)
        {
            if (Q[neighbors[x].id]==0 && L[v]+neighbors[x].weight<L[neighbors[x].id])
            {
                L[neighbors[x].id] = L[v] + neighbors[x].weight;
                P[neighbors[x].id] = v;
            }
        }
        free(neighbors);
    }

    free(L);
    free(Q);
    free(P);

    return st;
}
