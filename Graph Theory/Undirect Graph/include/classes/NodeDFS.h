#ifndef _NODEDFS_H_
#define _NODEDFS_H_

#include "Vertex.h"
#include <string>

class NodeDFS 
{
	private:

	Vertex father; // the father of this node
	Vertex index; // vertex that this node represents 
	std::vector<Vertex> edgesReturn; //  
	std::vector<Vertex> children; // the children of this node

	public:

	/**
	 * @brief      Constructs the object.
	 */
	NodeDFS();

	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  father  The father
	 * @param[in]  index   The index
	 */
	NodeDFS ( Vertex father, Vertex index );

	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  father    The father
	 * @param[in]  index     The index
	 * @param[in]  children  The children
	 */
	NodeDFS ( Vertex father, Vertex index, std::vector<Vertex> children);

	/**
	 * @brief      Destroys the object.
	 */
	~NodeDFS () = default;	 

	/**
	 * @brief      Gets the father.
	 *
	 * @return     The father.
	 */
	Vertex getFather ();

	/**
	 * @brief      Gets the index.
	 *
	 * @return     The index.
	 */
	Vertex getIndex ();

	/**
	 * @brief      Gets the children.
	 *
	 * @return     The children.
	 */
	std::vector<Vertex> getChildren ();

	/**
	 * @brief      Gets the edges return.
	 *
	 * @return     The edges return.
	 */
	std::vector<Vertex> getEdgesReturn ();	

	/**
	 * @brief      Sets the children.
	 *
	 * @param[in]  children  The children
	 */
	void setChildren ( std::vector<Vertex> children );

	/**
	 * @brief      Adds a child.
	 *
	 * @param[in]  newChild  The new child
	 */
	void addChild ( Vertex newChild );

	/**
	 * @brief      Adds an edge return.
	 *
	 * @param[in]  newEdgeReturn  The new edge return
	 */
	void addEdgeReturn ( Vertex newEdgeReturn );

	/**
	 * @brief      Returns a string representation of the object.
	 *
	 * @return     String representation of the object.
	 */
	std::string toString();

};

#endif