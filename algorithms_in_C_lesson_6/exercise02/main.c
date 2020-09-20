#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

void Dijkstra(GRAPH g, int start, int target, int **shortest_path, int *path_size, int *path_length);

int main()
{
    GRAPH g;
    int *shortest_path, path_size, path_length;
    int i, start=0, target=7;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    Dijkstra(g, start, target, &shortest_path, &path_size, &path_length);
    printf("\n\nShortest Path from %d to %d:\n", start, target);
    for (i=0; i<path_size; i++)
        printf("%d ", shortest_path[i]);
    printf("\nPath Length: %d", path_length);

    GR_destroy(g);
    free(shortest_path);

	return 0;
}

void Dijkstra(GRAPH g, int start, int target, int **shortest_path, int *path_size, int *path_length)
{
	int *Q, *L, *P;
	int i, x, v, cnt, vertices, neighbors_length;
	int infinity;
	elem *neighbors;
    QUEUE q;
    qelem qtemp;

    vertices = GR_vertices_count(g);

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
    QU_init(&q);
    qtemp.data = start;
    qtemp.priority = 0;
    cnt=0;
    while(cnt<vertices)
    {
        while(1)
        {
            QU_dequeue(&q, &qtemp);
            v = qtemp.data;
            if (Q[v]==0)
                break;
        }
        Q[v]=1;

        if (v==target) break;

        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (x=0; x<neighbors_length; x++)
        {
            if (Q[neighbors[x].id]==0 && L[v]+neighbors[x].weight<L[neighbors[x].id])
            {
                L[neighbors[x].id] = L[v] + neighbors[x].weight;
                P[neighbors[x].id] = v;
                qtemp.data = neighbors[x].id;
                qtemp.priority = L[neighbors[x].id];
                QU_enqueue(&q, qtemp);
            }
        }
        free(neighbors);
    }


    *path_size = 2;
    v = target;
    while(P[v]!=start)
    {
        v = P[v];
        (*path_size)++;
    }
    (*shortest_path) = (int *)malloc(sizeof(int)*(*path_size));
    if (!(*shortest_path))
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    v = target;
    for (i=*path_size-1; i>=0; i--)
    {
        (*shortest_path)[i] = v;
        v = P[v];
    }
    *path_length = L[target];

    free(L);
    free(Q);
    free(P);
}
