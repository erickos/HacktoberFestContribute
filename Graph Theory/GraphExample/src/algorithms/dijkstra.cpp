#include "algorithms/dijkstra.h"

void removeVertex (std::vector<Vertex> &freeSet, Vertex vertex)
{
	//graph.getVertex(vertex.getId()).setMark(true);
	for (auto it = freeSet.begin(); it != freeSet.end(); ++it )
	{
		if (it->getId() == vertex.getId()) 
		{
			freeSet.erase(it,it+1);
			break;
		}
	}
}

UGraph dijkstra (UGraph & graph)
{
	auto freeSet = graph.getVertices();

	//inicializate free set
	graph.getVertices()[0].setLabeledBy(graph.getVertices()[0].getId());
	graph.getVertices()[0].setPathWeight(0);
	
	// inicializate
	// for (unsigned int i=0; i < graph.getVertices().size(); i++)
	// 	graph.getVertices()[i].setMark(false);

	// mark root
	auto adjList = graph.getVertices()[0].getAdjList();
	for (unsigned int i=0; i < adjList.size(); i++)
	{
		graph.getVertex(adjList[i].getId()).setLabeledBy(graph.getVertices()[0].getId());
		graph.getVertex(adjList[i].getId()).setPathWeight(graph.getEdgeWeight(graph.getVertices()[0],adjList[i]));	
	}

	removeVertex(freeSet, graph.getVertices()[0]);

	while ( !(freeSet.empty()) )
	{	
		// choose the minimum
		Vertex *min = &graph.getVertex(freeSet[0].getId());

		// std::cout << "------------------------------------------\n";
		// std::cout << "Antes de selecionar, min é: " << min->getId() << "\n";
		for (unsigned int i=0; i < freeSet.size(); i++)
		{
			//std::cout << "Comparando: " << graph.getVertex(freeSet[i].getId()).getPathWeight() << " com " << min->getPathWeight() << "\n";
			if ( graph.getVertex(freeSet[i].getId()).getPathWeight() < min->getPathWeight() )
				min = &graph.getVertex(freeSet[i].getId());
		}
		// std::cout << "O menor escolhido foi: " << min->getId() << std::endl;
		// std::cout << "------------------------------------------\n";

		// auto vertexMin = graph.getVertex(min->getId());

		//mark min
		removeVertex(freeSet, *min);
		
		for (unsigned int i=0; i < min->getAdjList().size(); i++)
		{
			for ( unsigned int j=0; j < freeSet.size(); j++)
			{
				if (min->getAdjList()[i].getId() == freeSet[j].getId())
				{
					int pathWeight = min->getPathWeight() + graph.getEdgeWeight(*min, min->getAdjList()[i]);
					// std::cout << pathWeight << "\n";
					if (pathWeight < graph.getVertex(min->getAdjList()[i].getId()).getPathWeight())
					{
						// std::cout << "Id que vai receber o valor " << pathWeight << ": " << min->getAdjList()[i].getId();
						// std::cout << " que possui o valor " << min->getAdjList()[i].getPathWeight() << std::endl;
						min->getAdjList()[i].setLabeledBy(min->getId());
						min->getAdjList()[i].setPathWeight(pathWeight);
					
						graph.getVertex(min->getAdjList()[i].getId()).setLabeledBy(min->getId());
						graph.getVertex(min->getAdjList()[i].getId()).setPathWeight(pathWeight);

					}
				}	
			}
		}
	}
	return graph;
}