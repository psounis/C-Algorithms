#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

GRAPH BFSSpanningTree(GRAPH g, int start);

int main()
{
    GRAPH g, spanning_tree;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    spanning_tree = BFSSpanningTree(g, 0);
    printf("\n\nSpanning Tree\n");
    GR_print(spanning_tree);

    GR_destroy(g);
    GR_destroy(spanning_tree);


	return 0;
}

GRAPH BFSSpanningTree(GRAPH g, int start)
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
