#include "algorithms/reconnect.h"

Edge reconnect(UGraph graph, int bridge)
{
	graph.toString();
	graph.removeVertex(bridge);
	int components[graph.getVertices().size()];

	std::cout << "Grafo sem ponte\n";
	std::cout << graph.toString();

	int a = relatedComponent(graph, components);
	std::cout << a << std::endl;

	return Edge();
}

/**
 * @brief      search the related component in graph
 *
 * @param      graph       The graph
 * @param      components  The components
 *
 * @return     the number of related Component in graph
 */
int relatedComponent (UGraph &graph, int *components)
{
	int id = 0;
	// inicial
	for (unsigned int i=0; i < graph.getVertices().size(); i++)
		components[i] = -1;

	for (unsigned int i=0; i < graph.getVertices().size(); i++)
	{
		if (components[graph.getVertices()[i].getId() - 1] == -1)
			recursiveCC(graph, components, graph.getVertices()[i], id++);
	}
	return id;
}

void recursiveCC (UGraph &graph, int *components, Vertex vertex, int id)
{
	components[vertex.getId()-1] = id;
	std::cout << "Rotulei " << vertex.getId() << " com id :" << id << std::endl;
 	for (unsigned int i=0; i < graph.getVertex(vertex.getId()).getAdjList().size(); i++)
		if (components[graph.getVertex(vertex.getId()).getAdjList()[i].getId()-1] == -1)
			recursiveCC(graph, components, graph.getVertex(vertex.getId()).getAdjList()[i], id);
}