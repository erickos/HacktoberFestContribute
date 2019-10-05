#include "algorithms/dfs.h"

DFSTree dfs ( UGraph graph )
{
	std::vector<Vertex> vertices = graph.getVertices();
	std::stack<Vertex> stack;

	DFSTree tree( NodeDFS(vertices[0], vertices[0]) );
	recursiveDfs( vertices[0], stack, tree, graph );

	return tree;
}

void recursiveDfs ( Vertex vertex, std::stack<Vertex> &stack, DFSTree &tree, UGraph & graph )
{
	// mark vertex
	graph.getVertex(vertex.getId()).setMark(true);

	// add vertex in stack
	stack.push(vertex);

	// get the vertex adjacent list 
	std::vector<Vertex> adjList = graph.getAdjList(vertex);
	
	for ( unsigned int i=0; i < adjList.size(); ++i )
	{
		if ( !(graph.getVertex(adjList[i].getId()).isMark()) )
		{
			tree.addNode( NodeDFS(vertex, adjList[i]) );	
			recursiveDfs( adjList[i], stack, tree, graph );
		}
		else
		{
			auto aux = stack.top();
			stack.pop();
			if (!(stack.top().getId() == adjList[i].getId()))
			{
				tree.addEdgeReturn( adjList[i], vertex );			
			}
			stack.push(aux);
		}
	}

	stack.pop();
}	