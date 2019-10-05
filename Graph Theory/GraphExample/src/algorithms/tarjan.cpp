#include "algorithms/tarjan.h"

int calcLowpt ( DFSTree &tree, int index )
{
	auto node = tree.getNode(index);
	int min = index;

	for (unsigned int k=0; k < node.getEdgesReturn().size(); k++)
		if ( node.getEdgesReturn()[k].getId() < min ) min = node.getEdgesReturn()[k].getId();

	auto children = node.getChildren();
	for (unsigned int i=0; i < children.size(); i++)
	{
		auto nodeChild = tree.getNode(children[i].getId());

		for (unsigned int j=0; j < nodeChild.getEdgesReturn().size(); j++)
		{
			if ( nodeChild.getEdgesReturn()[j].getId() < min ) min = nodeChild.getEdgesReturn()[j].getId();
		}
		
		int auxMin = calcLowpt(tree, children[i].getId());
		if (auxMin < min) min = auxMin;
	}
	return min;

}

std::vector<int> calcAllLowpt ( DFSTree &tree )
{
	int sizeTree = tree.getTree().size();
	
	std::vector<int> preOrder = std::vector<int>(sizeTree);
	std::vector<int> lowpt = std::vector<int>(sizeTree);

	// inicializate preOrder
	for (int i = 1; i <= sizeTree; i++)
		preOrder[i-1] = i;

	for (int j= 0; j < sizeTree; j++)
		lowpt[j] = calcLowpt(tree, preOrder[j]);
	
	return lowpt;
}

bool isBridge (DFSTree &tree, std::vector<int> &lowpt, Vertex vertex)
{
	if (tree.getRoot().getIndex().getId() == vertex.getId())
	{
		if (tree.getRoot().getChildren().size() >= 2)
			return true;	
	}
	else
	{
		auto node = tree.getNode(vertex);
		auto nodeChildren = node.getChildren();

		for (unsigned int i=0; i < nodeChildren.size(); i++)
		{
			if ( lowpt[nodeChildren[i].getId()-1] == vertex.getId() ||
				 lowpt[nodeChildren[i].getId()-1] == nodeChildren[i].getId())
			{
				return true;
			}
		}	
	}
	
	return false;
}

std::vector<Vertex> UGraphBridges ( UGraph graph )
{

	auto tree = dfs(graph);
	auto lowpt = calcAllLowpt(tree);

	std::cout << "Tree\n";
	std::cout << tree.toString();

	std::cout << "Lowpts\n";

	for (unsigned int i=0; i < lowpt.size(); i++)
		std::cout << lowpt[i] << " ";
	std::cout << std::endl;

	std::vector<Vertex> vertices = graph.getVertices();
	std::vector<Vertex> bridges;

	for (unsigned int i =0; i < vertices.size(); i++)
	{
		if ( isBridge (tree, lowpt, vertices[i]) )
			bridges.push_back(vertices[i]);
	}

	return bridges;

}