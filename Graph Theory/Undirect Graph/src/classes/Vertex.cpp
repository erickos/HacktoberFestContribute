/**
 * Class for Vertex representation
 * 
 * author     Gabriel Araújo de Souza
 * e_mail     gabriel_feg@hotmail.com
 * date       Jun 2018 
 */

#include "classes/Vertex.h"

/**
 * @brief      Constructs the object. Create a null graph
 */
Vertex::Vertex ()
{
	id = -1;
	degree = -1;
}

/**
 * @brief      Basic Construct
 *
 * @param[in]  id    The vertex identifier
 */
Vertex::Vertex ( int id )
{
	this->id = id;
	this->degree = 0;
	adjList = std::vector<Vertex>();
}

/**
 * @brief      Gets the degree.
 *
 * @return     The degree.
 */
int Vertex::getDegree ()
{
	return degree;
}

/**
 * @brief      Gets the identifier.
 *
 * @return     The identifier.
 */
int Vertex::getId ()
{
	return this->id;
}

/**
 * @brief      Gets the adjacency list.
 *
 * @return     The adj vector.
 */
std::vector<Vertex> & Vertex::getAdjList ()
{
	return this->adjList;
}

/**
 * @brief      Sets the identifier.
 *
 * @param[in]  newId  The new identifier
 */
void Vertex::setId ( int newId )
{
	this->id = newId;
}

/**
 * @brief      Sets the adj list.
 *
 * @param[in]  newAdjvector  The new adj vector
 */	
void Vertex::setAdjList ( std::vector<Vertex> newAdjList )
{
	this->adjList = newAdjList;
}

/**
 * @brief      Adds an edge.
 *
 * @param[in]  vertex  The vertex
 */
void Vertex::addEdge ( Vertex vertex )
{
	adjList.push_back( vertex );
	degree++;
}

/**
 * @brief      Removes an edge.
 *
 * @param[in]  vertex  The vertex that represent edge 
 */
void Vertex::removeEdge ( Vertex vertex )
{
	if ( adjList.empty() ) return;

	for (auto it = adjList.begin(); it != adjList.end(); ++it )
	{
		if ( *it == vertex )
		{
			adjList.erase(it, it+1);
			break;
		}
	}
}

/**
 * @brief      Determines if adj.
 *
 * @param[in]  vertex  The vertex
 *
 * @return     True if adj, False otherwise.
 */
bool Vertex::isAdj ( Vertex vertex )
{
	for ( int i=0; i < this->getDegree(); i++ )
		if ( this->adjList[i] == vertex ) return true;

	return false;
}

/**
 * @brief      Returns a string representation of the object.
 *
 * @return     String representation of the object.
 */
std::string Vertex::toString()
{
	std::string value = "( ";
	value += std::to_string( this->getId() ) + " ){ ";
	for (unsigned int i = 0; i < adjList.size(); i++)
		value += std::to_string( adjList[i].getId() ) + " ";
	value += "}\n";

	return value;

} 

/**
 * @brief      Determines if mark.
 *
 * @return     True if mark, False otherwise.
 */
bool Vertex::isMark ()
{
	return this->mark;
}

/**
 * @brief      Sets the mark.
 *
 * @param[in]  mark  The mark
 */
void Vertex::setMark ( bool mark )
{
	this->mark = mark;
}

/**
 * @brief      Gets the labeled by.
 *
 * @return     The labeled by.
 */
int Vertex::getLabeledBy ()
{
	return this->labeledBy;
}

/**
 * @brief      Gets the path weight.
 *
 * @return     The path weight.
 */
int Vertex::getPathWeight ()
{
	return this->pathWeight;
}

/**
 * @brief      Sets the labeled by.
 *
 * @param[in]  labeledBy  The labeled by
 */
void Vertex::setLabeledBy (int labeledBy)
{
	this->labeledBy = labeledBy;
}

/**
 * @brief      Sets the path weight.
 *
 * @param[in]  pathWeight  The path weight
 */
void Vertex::setPathWeight (int pathWeight)
{
	this->pathWeight = pathWeight;
}





