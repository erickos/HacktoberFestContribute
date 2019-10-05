#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <vector>
#include <iostream>
#include <string>

class Vertex
{
	private:
	/**
	 * Attributes
	 */

	int id; // vertex id
	unsigned int degree; // vertex degree
	std::vector<Vertex> adjList; // vertex adjacency vector
	bool mark = false; // auxiliary for DFS  
	int labeledBy = -1; // auxiliary for Dijkstra
	int pathWeight = 999999999; // auxiliary for Dijkstra

	public:

	/**
	 * @brief      Constructs the object. Create a null graph
	 */
	Vertex ();

	/**
	 * @brief      Basic Construct
	 *
	 * @param[in]  id    The vertex identifier
	 */
	Vertex ( int id );

	/**
	 * @brief      Destroys the object.
	 */
	~Vertex () = default;

	/**
	 * @brief      assigns a new vertex
	 *
	 * @param[in]  rhs   The right hand side
	 *
	 * @return     a new vertex equals rhs vertex
	 */
	Vertex & operator=( const Vertex & rhs )
	{
		id = rhs.id;
		degree = rhs.degree;
		adjList = rhs.adjList;
		labeledBy = rhs.labeledBy;
		pathWeight = rhs.pathWeight;

		return *this;
	}

	/**
	 * @brief      verify if two vertex are equals
	 *
	 * @param[in]  rhs   The right hand side
	 *
	 * @return     true if equals, false otherwise
	 */
	bool operator==( const Vertex & rhs )
	{
		if (id == rhs.id)
			return true;

		return false;
	}

	/**
	 * @brief      verify if two vertex are differents
	 *
	 * @param[in]  rhs   The right hand side
	 *
	 * @return     true if differents, false otherwise
	 */
	bool operator!=( const Vertex & rhs )
	{
		if (id != rhs.id or degree != rhs.degree)
			return true;
		return false;
	}

	/**
	 * @brief      Gets the degree.
	 *
	 * @return     The degree.
	 */
	int getDegree ();

	/**
	 * @brief      Gets the identifier.
	 *
	 * @return     The identifier.
	 */
	int getId ();

	/**
	 * @brief      Gets the adjacency list.
	 *
	 * @return     The adj vector.
	 */
	std::vector<Vertex> & getAdjList ();

	/**
	 * @brief      Sets the identifier.
	 *
	 * @param[in]  newId  The new identifier
	 */
	void setId ( int newId ); 
	
	/**
	 * @brief      Sets the adj list.
	 *
	 * @param[in]  newAdjvector  The new adj vector
	 */
	void setAdjList ( std::vector<Vertex> newAdjvector );

	/**
	 * @brief      Adds an edge.
	 *
	 * @param[in]  vertex  The vertex
	 */
	void addEdge ( Vertex vertex );
	
	/**
	 * @brief      Removes an edge.
	 *
	 * @param[in]  vertex  The vertex that represent edge 
	 */
	void removeEdge ( Vertex vertex );

	/**
	 * @brief      Determines if adj.
	 *
	 * @param[in]  vertex  The vertex
	 *
	 * @return     True if adj, False otherwise.
	 */
	bool isAdj ( Vertex vertex );

	/**
	 * @brief      Returns a string representation of the object.
	 *
	 * @return     String representation of the object.
	 */
	std::string toString(); 

	/**
	 * @brief      Determines if mark.
	 *
	 * @return     True if mark, False otherwise.
	 */
	bool isMark ();

	/**
	 * @brief      Sets the mark.
	 *
	 * @param[in]  mark  The mark
	 */
	void setMark ( bool mark );

	/**
	 * @brief      Gets the labeled by.
	 *
	 * @return     The labeled by.
	 */
	int getLabeledBy ();

	/**
	 * @brief      Gets the path weight.
	 *
	 * @return     The path weight.
	 */
	int getPathWeight ();

	/**
	 * @brief      Sets the labeled by.
	 *
	 * @param[in]  labeledBy  The labeled by
	 */
	void setLabeledBy (int labeledBy);

	/**
	 * @brief      Sets the path weight.
	 *
	 * @param[in]  pathWeight  The path weight
	 */
	void setPathWeight (int pathWeight);

};

#endif