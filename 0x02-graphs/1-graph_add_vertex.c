#include "graphs.h"

/**
 * create_vertex - Create a new vertex and initialize it
 * @string: The string to store in the vertex
 * @index: The index number of the vertex
 * Return: The address of the new vertex
*/

vertex_t *create_vertex(const char *string, size_t index)
{
	vertex_t *new_vertex;

	new_vertex = malloc(sizeof(vertex_t));
	if (!new_vertex)
		return (NULL);

	new_vertex->index = index;
	new_vertex->content = strdup(string);
	new_vertex->nb_edges = 0;
	new_vertex->edges = NULL;
	new_vertex->next = NULL;

	return (new_vertex);
}

/**
 * graph_add_vertex - Adds a vertex
 * @graph: The address of the graph to add the vertex to
 * @str: The string/content to add to the vertex
 * Return: The address of the new vertex
*/

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t **vertex;

	if (!graph || !str)
		return (NULL);

	for (vertex = &graph->vertices; *vertex; vertex = &(*vertex)->next)
		if (strcmp(str, (*vertex)->content) == 0)
			return (NULL);

	*vertex = create_vertex(str, graph->nb_vertices);
	graph->nb_vertices += 1;

	return (*vertex);
}
