#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

void BFSShortestPath(GRAPH g, int start, int target, int **shortest_path, int *path_size);

int main()
{
    GRAPH g;
    int path_size, *shortest_path;
    int i, start=0, target=7;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    BFSShortestPath(g, start, target, &shortest_path, &path_size);
    printf("\n\nShortest Path from %d to %d\n", start, target);
    for (i=0; i<path_size; i++)
        printf("%d ", shortest_path[i]);

    GR_destroy(g);
    free(shortest_path);

	return 0;
}

void BFSShortestPath(GRAPH g, int start, int target, int **shortest_path, int *path_size)
{
	QUEUE qu;
	int *discovered, *parent;
	int i, v, vertices, neighbors_length;
	int stop_loop, *neighbors;

    vertices = GR_vertices_count(g);

    discovered = (int *)malloc(sizeof(int)*vertices);
    if (!discovered)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    for (i=0; i<vertices; i++)
        discovered[i] = 0;

    parent = (int *)malloc(sizeof(int)*vertices);
    if (!parent)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    for (i=0; i<vertices; i++)
        parent[i] = -1;


    QU_init(&qu);
    QU_enqueue(&qu, start);
    discovered[start]=1;
    parent[start]=start;
    stop_loop=FALSE;
    while(!QU_empty(qu)&&!stop_loop)
    {
        QU_dequeue(&qu, &v);
        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (i=0; i<neighbors_length; i++)
        {
            if (!discovered[neighbors[i]])
            {
                discovered[neighbors[i]]=1;
                parent[neighbors[i]]=v;
                QU_enqueue(&qu, neighbors[i]);
                if (target==neighbors[i])
                {
                    stop_loop=TRUE;
                    break;
                }
            }
        }
        free(neighbors);
    }

    *path_size = 2;
    v = target;
    while(parent[v]!=start)
    {
        v = parent[v];
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
        v = parent[v];
    }

    QU_destroy(&qu);
    free(parent);
	free(discovered);
}
