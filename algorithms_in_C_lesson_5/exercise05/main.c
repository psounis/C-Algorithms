#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"

void DFSSequence(GRAPH g, int start, int **sequence, int *sequence_size);

int main()
{
    GRAPH g;
    int i, *sequence, sequence_size;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    DFSSequence(g, 0, &sequence, &sequence_size);

    printf("\nDFS Sequence: ");
    for (i=0; i<sequence_size; i++)
        printf("%d ", sequence[i]);

    GR_destroy(g);
    free(*sequence);

	return 0;
}

void DFSSequence(GRAPH g, int start, int **sequence, int *sequence_size)
{
	GRAPH st;
	STACK s;
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

    (*sequence) = (int *)malloc(sizeof(int)*vertices);
    if (!(*sequence))
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    *sequence_size = vertices;

    ST_init(&s);

    ST_push(&s, start);
    cnt=0;
    stop_loop=FALSE;
    while(!ST_empty(s)&&!stop_loop)
    {
        ST_pop(&s, &v);
        if (!discovered[v])
        {
            discovered[v]=1;
            (*sequence)[cnt]=v;
            cnt++;
            if (cnt==vertices)
            {
                stop_loop=TRUE;
                break;
            }
            GR_neighbors(g, v, &neighbors_length, &neighbors);
            for (i=neighbors_length-1; i>=0; i--)
                ST_push(&s, neighbors[i]);
            free(neighbors);
        }
    }
    ST_destroy(&s);
	free(discovered);
}
