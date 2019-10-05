#include "classes/DFSTree.h"

/**
 * @brief      Constructs the object.
 *
 * @param[in]  root  The root
 */
DFSTree::DFSTree ( NodeDFS root )
{
	this->tree.clear();
	this->tree.push_back(root);
}

/**
 * @brief      Gets the root.
 *
 * @return     The root.
 */
NodeDFS DFSTree::getRoot ()
{
	return tree[0];
}

/**
 * @brief      Gets the tree.
 *
 * @return     The tree.
 */
std::vector<NodeDFS> DFSTree::getTree ()
{
	return this->tree;
}

/**
 * @brief      Gets the node.
 *
 * @param[in]  index  The index
 *
 * @return     The node.
 */
NodeDFS DFSTree::getNode ( int index )
{
	for (unsigned int i=0; i < tree.size(); i++)
		if ( tree[i].getIndex().getId() == index ) return tree[i];

	return NodeDFS();
}

/**
 * @brief      Gets the node.
 *
 * @param[in]  vertex  The vertex
 *
 * @return     The node.
 */
NodeDFS DFSTree::getNode ( Vertex vertex )
{
	return this->getNode(vertex.getId());
}

/**
 * @brief      Adds a node.
 *
 * @param[in]  node  The node
 */
void DFSTree::addNode ( NodeDFS node )
{
	this->tree.push_back(node);
	for (unsigned int i=0; i < tree.size(); i++)
		if (tree[i].getIndex().getId() == node.getFather().getId())
			tree[i].addChild(node.getIndex());
}

/**
 * @brief      Adds an edge return.
 *
 * @param[in]  father  The father
 * @param[in]  child   The child
 */
void DFSTree::addEdgeReturn ( Vertex father, Vertex child )
{
	for (unsigned int i=0; i < this->tree.size(); i++ )
	{
		if ( tree[i].getIndex().getId() == child.getId() )
			tree[i].addEdgeReturn(father);
	}
}

/**
 * @brief      Returns a string representation of the object.
 *
 * @return     String representation of the object.
 */
std::string DFSTree::toString()
{
	std::string value="";
	for (unsigned int i=0; i < tree.size(); i++)
		value += tree[i].toString();
	return value;	
}
