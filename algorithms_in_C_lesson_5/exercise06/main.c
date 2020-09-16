#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"

GRAPH DFSForest(GRAPH g);

int main()
{
    GRAPH g, spanning_forest;

    GR_init_from_file(&g, "graph2.graph");
    printf("Initial Graph\n");
    GR_print(g);

    spanning_forest = DFSForest(g);
    printf("\n\nSpanning Forest\n");
    GR_print(spanning_forest);

    GR_destroy(g);
    GR_destroy(spanning_forest);


	return 0;
}

GRAPH DFSForest(GRAPH g)
{
	GRAPH st;
	STACK s;
	selem edge;
	int *discovered;
	int i, v, cnt, vertices, neighbors_length;
	int stop_loop, *neighbors;
	int start;

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

    cnt=0;
    while(1)
    {
        if (cnt<vertices)
        {
            for (i=0; i<vertices; i++)
                if (discovered[i]==0)
                {
                    start=i;
                    break;
                }
        }
        else break;

        ST_init(&s);
        discovered[start]=1;
        cnt++;
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

    }
	free(discovered);
	return st;
}
