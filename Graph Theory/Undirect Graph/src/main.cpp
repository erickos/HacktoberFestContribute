#include <iostream>
#include <cassert>
#include "classes/UGraph.h"
#include <vector>
#include <fstream>
#include <fstream>

int main ( )
{
	std::vector<Vertex> vertices;
	std::vector<Edge> edges;

	vertices  = {1,2,3,4,5,6,7,8,9,10,11,12};
	edges = {{1,2,3}, {2,3,4}, {3,4,8}, {2,5,2}, 
		 {5,6,1}, {6,7,7}, {7,8,3},
	 	 {8,9,5}, {6,9,4},  {5,10,9},
		 {10,11,5}, {10,12,2}};
	
	vertices  = {1,2,3,4,5,6,7,8,9,10};
	edges = {{1,2,3}, {1,3,4}, {1,8,8}, 
		 {8,9,2}, {9,10,1}, {2,4,7},
		 {2,5,3}, {5,4,5}, {5,6,4},
		 {6,4,9}, {6,7,5}};

	/*	
	int reader;
	bool signalT = true;
	while (std::cin >> reader )
	{
		if (signalT)
		{
			for (int i=1; i <= reader; i++)
				vertices.push_back(Vertex(i));
		}

		int source;
		int sink;
		int peso;

		if (signalT)
			std::cin >> source;
		else source = reader;
		std::cin >> sink;
		std::cin >> peso;
		
		edges.push_back(Edge(source, sink, (int)peso));
		signalT = false;
	}
	*/

	std::cout << vertices.size();
	std::cout << edges.size();

	UGraph graph = UGraph(vertices, edges);
	std::cout << graph.toString();

	std::cout << "----------------------------\n";

	return 0;
}
