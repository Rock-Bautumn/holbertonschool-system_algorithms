#include "graphs.h"

/**
 * create_edge - Create and initialize a new edge
 * @dest: The destination of the vertex
 * @src: the original source vertex
 * Return: true if success, false if failure
 */

int create_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *new_edge, **edge_list;

	if (dest == NULL || src == NULL)
		return (false);

	edge_list = &src->edges;
	for (; *edge_list; edge_list = &(*edge_list)->next)
		if ((*edge_list)->dest == dest)
			return (false);

	new_edge = malloc(sizeof(edge_t));

	if (!new_edge)
		return (false);

	new_edge->dest = dest;
	new_edge->next = NULL;

	*edge_list = new_edge;

	src->nb_edges += 1;

	return (true);
}

/**
 * vertex_search - Search for a vertex in a graph
 *
 * @graph: The address of the graph to search in
 * @content: The content to search the vertices for
 * Return: The address of the matching vertex, or NULL if not found
 */
vertex_t *vertex_search(graph_t *graph, const char *content)
{
	vertex_t *this_vertex = graph->vertices;

	for (; this_vertex; this_vertex = this_vertex->next)
		if (strcmp(this_vertex->content, content) == 0)
			return (this_vertex);

	return (NULL);
}

/**
 * graph_add_edge - Add an edge between two vertices
 *
 * @graph: The address of the graph to add the edge to
 * @src: The string to match to make the connection from
 * @dest: The string to match to make the connection to
 * @type: The edge type
 * Return: true if success, false if failure
 **/
int graph_add_edge(
	graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	vertex_t *vertex_src, *vertex_dest;

	if (!graph || !src || !dest || type > BIDIRECTIONAL)
		return (false);

	vertex_src = vertex_search(graph, src);
	if (!vertex_src)
		return (false);

	vertex_dest = vertex_search(graph, dest);
	if (!vertex_dest)
		return (false);

	if (type == UNIDIRECTIONAL)
		return (create_edge(vertex_src, vertex_dest));

	create_edge(vertex_src, vertex_dest);
	create_edge(vertex_dest, vertex_src);

	return (true);
}
