#include "classes/NodeDFS.h"

NodeDFS::NodeDFS ()
{
	this->father = Vertex();
	this->index = Vertex();
}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  father  The father
 * @param[in]  index   The index
 */
NodeDFS::NodeDFS ( Vertex father, Vertex index )
{
	this->father = father;
	this->index = index;
}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  father    The father
 * @param[in]  index     The index
 * @param[in]  children  The children
 */
NodeDFS::NodeDFS ( Vertex father, Vertex index, std::vector<Vertex> children)
{
	this->father = father;
	this->index = index;
	this->children = children;
}

/**
 * @brief      Gets the father.
 *
 * @return     The father.
 */
Vertex NodeDFS::getFather ()
{
	return this->father; 
}

/**
 * @brief      Gets the index.
 *
 * @return     The index.
 */
Vertex NodeDFS::getIndex ()
{
	return this->index;
}

/**
 * @brief      Gets the children.
 *
 * @return     The children.
 */
std::vector<Vertex> NodeDFS::getChildren ()
{
	return this->children;
}

/**
 * @brief      Sets the children.
 *
 * @param[in]  children  The children
 */
void NodeDFS::setChildren ( std::vector<Vertex> children )
{
	this->children = children;
}

/**
 * @brief      Adds a child.
 *
 * @param[in]  newChild  The new child
 */
void NodeDFS::addChild ( Vertex newChild )
{
	this->children.push_back(newChild);
}

/**
 * @brief      Returns a string representation of the object.
 *
 * @return     String representation of the object.
 */
std::string NodeDFS::toString()
{
	std::string value = "<";
	
	value += std::to_string(father.getId()) + ", ";
	value += std::to_string(index.getId()) + ", { ";

	std::vector<Vertex> v = this->getEdgesReturn();
	for (unsigned int j=0; j < v.size(); j++ )
		value += std::to_string(v[j].getId()) + " ";
	value += "}[";

	v = this->getChildren();
	for (unsigned int j=0; j < v.size(); j++ )
		value += std::to_string(v[j].getId()) + " ";
	value += "]>\n";
	return value;
}

/**
 * @brief      Adds an edge return.
 *
 * @param[in]  newEdgeReturn  The new edge return
 */
void NodeDFS::addEdgeReturn ( Vertex newEdgeReturn )
{
	this->edgesReturn.push_back(newEdgeReturn);
}

/**
 * @brief      Gets the edges return.
 *
 * @return     The edges return.
 */
std::vector<Vertex> NodeDFS::getEdgesReturn ()
{
	return this->edgesReturn;
}