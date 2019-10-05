#ifndef _DFSTREE_H_
#define _DFSTREE_H_

#include "NodeDFS.h"

class DFSTree
{
	private:
	
	std::vector<NodeDFS> tree; // tree nodes

	public:

	/**
	 * @brief      Constructs the object.
	 */
	DFSTree ();

	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  root  The root
	 */
	DFSTree ( NodeDFS root );

	/**
	 * @brief      Destroys the object.
	 */
	~DFSTree () = default;

	/**
	 * @brief      Gets the root.
	 *
	 * @return     The root.
	 */
	NodeDFS getRoot ();

	/**
	 * @brief      Gets the tree.
	 *
	 * @return     The tree.
	 */
	std::vector<NodeDFS> getTree ();

	/**
	 * @brief      Gets the node.
	 *
	 * @param[in]  index  The index
	 *
	 * @return     The node.
	 */
	NodeDFS getNode ( int index );

	/**
	* @brief      Gets the node.
	*
	* @param[in]  vertex  The vertex
	*
	* @return     The node.
	*/
	NodeDFS getNode ( Vertex vertex );

	/**
	 * @brief      Adds a node.
	 *
	 * @param[in]  node  The node
	 */
	void addNode ( NodeDFS node );
	
	/**
	 * @brief      Adds an edge return.
	 *
	 * @param[in]  father  The father
	 * @param[in]  child   The child
	 */
	void addEdgeReturn ( Vertex father, Vertex child );

	/**
	 * @brief      Returns a string representation of the object.
	 *
	 * @return     String representation of the object.
	 */
	std::string toString();


};

#endif