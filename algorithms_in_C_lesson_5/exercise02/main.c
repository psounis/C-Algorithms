#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

void BFSSequence(GRAPH g, int start, int **sequence, int *sequence_size);

int main()
{
    GRAPH g;
    int i, *sequence, sequence_size;

    GR_init_from_file(&g, "graph1.graph");
    printf("Initial Graph\n");
    GR_print(g);

    BFSSequence(g, 0, &sequence, &sequence_size);
    printf("\n\nSequence:\n");
    for (i=0; i<sequence_size; i++)
        printf("%d ", sequence[i]);

    GR_destroy(g);
    free(sequence);
	return 0;
}

void BFSSequence(GRAPH g, int start, int **sequence, int *sequence_size)
{
	QUEUE qu;
	int *discovered;
	int i, v, cnt, vertices, neighbors_length;
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

    *sequence = (int *)malloc(sizeof(int)*vertices);
    if (!(*sequence))
    {
        printf("Error Allocating Memory!");
        exit(0);
    }

    QU_init(&qu);
    QU_enqueue(&qu, start);
    discovered[start]=1;
    (*sequence)[0]=start;
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
                (*sequence)[cnt]=neighbors[i];
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

    (*sequence_size)=cnt;
    QU_destroy(&qu);
	free(discovered);
}
