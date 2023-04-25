#include "graphs.h"

/**
 * depth_traversal - Traverse the graph by depth first
 * @vertex: The current edge's destination vertex
 * @visited: The array of the visited vertices
 * @entry_depth: The current depth
 * @action: The function to perform during a visit
 * Return: The maximum depth
 */

size_t depth_traversal(
	const vertex_t *vertex, int *visited, size_t entry_depth,
	void (*action)(const vertex_t *, size_t))
{
	size_t max_depth = entry_depth, this_depth;
	edge_t *current_edge;

	if (visited[vertex->index] == 0)
	{
		action(vertex, entry_depth);
		visited[vertex->index] = 1;
	}

	current_edge = vertex->edges;

	while (current_edge != NULL)
	{
		if (visited[current_edge->dest->index] == 0)
		{
			this_depth = depth_traversal(current_edge->dest,
				visited, entry_depth + 1, action);
			if (this_depth > max_depth)
				max_depth = this_depth;
		}
		current_edge = current_edge->next;
	}

	return (max_depth);
}

/**
 * depth_first_traversal - Entry point for traversing by depth first
 * @graph: The address of the graph to traverse
 * @action: A function pointer for the function to be called for
 * each visited vertex
 * Return: The maximum vertex depth, or 0 if failure
 */

size_t depth_first_traverse(
	const graph_t *graph, void (*action)(const vertex_t *, size_t))
{
	int *visited;
	size_t max_depth = 0;

	if (graph == NULL || action == NULL || graph->vertices == NULL)
		return (0);

	visited = malloc(sizeof(int) * graph->nb_vertices);

	if (visited == NULL)
		return (0);

	while (max_depth < graph->nb_vertices)
		visited[max_depth++] = 0;

	max_depth = depth_traversal(graph->vertices, visited, 0, action);

	free(visited);

	return (max_depth);
}
