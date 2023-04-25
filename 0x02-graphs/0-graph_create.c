#include "graphs.h"

/**
 * graph_create - Create a new graph
 * Return: The address of the newly created graph
*/

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
