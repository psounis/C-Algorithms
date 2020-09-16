#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"

GRAPH DFSSpanningTree(GRAPH g, int start);

int main()
{
    GRAPH g, spanning_tree;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    spanning_tree = DFSSpanningTree(g, 0);
    printf("\n\nSpanning Tree\n");
    GR_print(spanning_tree);

    GR_destroy(g);
    GR_destroy(spanning_tree);


	return 0;
}

GRAPH DFSSpanningTree(GRAPH g, int start)
{
	GRAPH st;
	STACK s;
	selem edge;
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

    ST_init(&s);
    discovered[start]=1;
    cnt=1;
    GR_neighbors(g, start, &neighbors_length, &neighbors);
    for (i=neighbors_length-1; i>=0; i--)
    {
        edge.node = neighbors[i], edge.parent = start;
        ST_push(&s, edge);
    }
    free(neighbors);

    stop_loop=FALSE;
    while(!ST_empty(s)&&!stop_loop)
    {
        ST_pop(&s, &edge);
        v = edge.node;
        if (!discovered[v])
        {
            discovered[v]=1;
            GR_add_edge(st, v, edge.parent);
            cnt++;
            if (cnt==vertices)
            {
                stop_loop=TRUE;
                break;
            }
            GR_neighbors(g, v, &neighbors_length, &neighbors);
            for (i=neighbors_length-1; i>=0; i--)
            {
                edge.node = neighbors[i], edge.parent = v;
                ST_push(&s, edge);
            }
            free(neighbors);
        }
    }
    ST_destroy(&s);
	free(discovered);
	return st;
}
