#include "graphs.h"

graph_t *graph_create(void)
{
	graph_t *graph = malloc(sizeof(graph_t));

	if (graph)
	{
		graph->vertices = NULL;
		graph->nb_vertices = 0;
	}

	return (graph);
}
