#include "graphs.h"
/**
 * graph_delete - Free a graph and its associated members
 * @graph: The address of the graph to free
 **/
void graph_delete(graph_t *graph)
{
	vertex_t *vertex, *free_vertex;
	edge_t *edge, *free_edge;

	if (graph == NULL)
		return;

	vertex = graph->vertices;
	while (vertex)
	{
		free(vertex->content);
		edge = vertex->edges;
		while (edge)
		{
			free_edge = edge;
			edge = edge->next;
			free(free_edge);
		}
		free_vertex = vertex;
		vertex = vertex->next;
		free(free_vertex);
	}

	free(graph);
}
