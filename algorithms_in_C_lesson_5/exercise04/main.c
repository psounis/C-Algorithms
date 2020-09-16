#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

int BFSBipartite(GRAPH g);

int main()
{
    GRAPH g;

    GR_init_from_file(&g, "graph2.graph");
    printf("Initial Graph\n");
    GR_print(g);

    BFSBipartite(g);

    GR_destroy(g);


	return 0;
}

int BFSBipartite(GRAPH g)
{
	QUEUE qu;
	int *discovered;
	int i, v, cnt, vertices, neighbors_length;
	int stop_loop, *neighbors;
	int start = 0, bipartite;

    vertices = GR_vertices_count(g);

    discovered = (int *)malloc(sizeof(int)*vertices);
    if (!discovered)
    {
        printf("Error Allocating Memory!");
        exit(0);
    }
    for (i=0; i<vertices; i++)
        discovered[i] = -1;

    QU_init(&qu);
    QU_enqueue(&qu, start);
    discovered[start]=0;
    cnt=1; stop_loop=FALSE;
    bipartite=TRUE;
    while(!QU_empty(qu)&&!stop_loop)
    {
        QU_dequeue(&qu, &v);
        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (i=0; i<neighbors_length; i++)
        {
            if (discovered[neighbors[i]]==-1)
            {
                if (discovered[v]==0)
                    discovered[neighbors[i]]=1;
                else
                    discovered[neighbors[i]]=0;

                QU_enqueue(&qu, neighbors[i]);
                cnt++;
            }
            else if (discovered[neighbors[i]]==discovered[v])
            {
                stop_loop=TRUE;
                bipartite=FALSE;
                break;
            }
        }
        free(neighbors);
    }

    if (bipartite)
    {
        printf("Graph is bipartite.\nA: ");
        for (i=0; i<vertices; i++)
            if (discovered[i]==0)
                printf("%d ", i);
        printf("\nB: ");
        for (i=0; i<vertices; i++)
            if (discovered[i]==1)
                printf("%d ", i);

        QU_destroy(&qu);
        free(discovered);
        return TRUE;
    }
    else
    {
        printf("Graph is not bipartite.\n ");
        QU_destroy(&qu);
        free(discovered);
        return FALSE;
    }
}
