/**
 * Class for Graph representation
 * 
 * author     Gabriel Araújo de Souza
 * e_mail     gabriel_feg@hotmail.com
 * date       Jun 2018 
 */

#include "classes/UGraph.h"

/**
 * @brief      Constructs the object.
 */
UGraph::UGraph ()
{
	Vertex aux = Vertex();
	this->vertices.push_back( aux );
}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  numOfVertices  The number of vertices
 */
UGraph::UGraph ( int numOfVertices )
{
	for (int i=0; i < numOfVertices; i++)
		this->vertices.push_back( Vertex(i) );
}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  vertices  The vertices
 * @param[in]  edges     The edges
 */
UGraph::UGraph ( std::vector<Vertex> vertices, std::vector<Edge> edges )
{
	std::cout << "entrou\n";
	this->vertices = vertices;

	for (unsigned int i=0; i < edges.size(); i++)
		this->addEdge(edges[i]);
}

/**
 * @brief      Adds an edge.
 *
 * @param[in]  source  The source
 * @param[in]  sink    The sink
 * @param[in]  weight  The weight
 */
void UGraph::addEdge (int source, int sink, int weight)
{
	auto vSource = getVertex(source);
	auto vSink   = getVertex(sink);
	
	if ( (vSource.getDegree() != -1) and ( vSink.getDegree() != -1) )
	{
		for ( unsigned int i=0; i < vertices.size(); i++)
		{
			if (vertices[i].getId() == source )
				vertices[i].addEdge(vSink);
			else if (vertices[i].getId() == sink)
				vertices[i].addEdge(vSource);
		}

		edges.push_back( Edge(source, sink, weight) );
	}
}

/**
 * @brief      Adds an edge.
 *
 * @param[in]  source  The edge source
 * @param[in]  sink    The edge weight
 */
void UGraph::addEdge (Vertex source, Vertex sink, int weight)
{
	this->addEdge(source.getId(), sink.getId(), weight);
}

/**
 * @brief      Adds an edge.
 *
 * @param[in]  edge  The edge
 */
void UGraph::addEdge (Edge edge)
{
	this->addEdge(edge.getSource(), edge.getSink(), edge.getWeight());
}

/**
 * @brief      Adds a vertex.
 *
 * @param[in]  v    The vertex
 */
void UGraph::addVertex (Vertex v)
{
	vertices.push_back(v);
}

/**
 * @brief      Removes an edge.
 *
 * @param[in]  source  The source identifier
 * @param[in]  sink    The sink identifier
 *
 * @return     True if it could remove, false otherwise
 */
bool UGraph::removeEdge ( Edge edge )
{
	if ( edges.empty() ) return false;

	for ( auto it = edges.begin(); it != edges.end(); ++it )
	{
		if ((it->getSource() == edge.getSource() ) and (it->getSink() == edge.getSink()) ) 
		{
			edges.erase(it, it+1);
			
			// remove vertex adjacency
			this->getVertex(edge.getSource().getId()).removeEdge( edge.getSink() );
			this->getVertex(edge.getSink().getId()).removeEdge( edge.getSource() );

			return true;
		} else if ((it->getSink() == edge.getSource()) and (it->getSource() == edge.getSink()))
		{
			edges.erase(it, it+1);

			// remove vertex adjacency
			getVertex(edge.getSource().getId()).removeEdge( edge.getSource() );
			getVertex(edge.getSink().getId()).removeEdge( edge.getSink() );

			return true;
		}
	}

	return false;
}


/**
 * @brief      Removes a vertex.
 *
 * @param[in]  idVertex  vertex identifier
 *
 * @return     True if it could remove, false otherwise
 */
bool UGraph::removeVertex ( int idVertex )
{
	for ( auto it = vertices.begin(); it != vertices.end(); it++)
	{
		if ( it->getId() == idVertex)
		{
			vertices.erase(it, it+1);
			std::vector<Edge> edgesForRemove;
			for (unsigned int i = 0; i < edges.size(); i++)
			{
				if ( (edges[i].getSource().getId() == idVertex) or 
				     (edges[i].getSink().getId() == idVertex) )
				{
					edgesForRemove.push_back(edges[i]);
				}
			}

			for (unsigned int i = 0; i < edgesForRemove.size(); i++)
				this->removeEdge(edgesForRemove[i]);
							
			return true;
		}
	}
	return false;
}

/**
 * @brief      Removes a vertex.
 *
 * @param[in]  vertex  The vertex
 *
 * @return     True if it could remove, false otherwise
 */
bool UGraph::removeVertex ( Vertex vertex )
{
	return this->removeVertex(vertex.getId());
}

/**
 * @brief      Returns a string representation of the object.
 *
 * @return     String representation of the object.
 */
std::string UGraph::toString ()
{
	std::string value = "Graph\n";
	value += "(Node){Adjacent Vertices}\n";
	for (unsigned int i=0; i < vertices.size(); i++)
		value += vertices[i].toString();

	value += "------------------------------------\n";
	value += "Edges list\n";
	value += "<source, sink>[weight]\n";

	for (unsigned int i=0; i < edges.size(); i++)
		value+= edges[i].toString();
	
	return value;
}

/**
 * @brief      Determines if vertex contained in this graph.
 *
 * @param[in]  idVertex  The vertex identifier
 *
 * @return     True if vertex contained, False otherwise.
 */
bool UGraph::isVertexContained ( int idVertex )
{
	for ( auto i = this->vertices.begin(); i != this->vertices.end(); ++i)
		if ( i->getId() == idVertex ) return true;
	return false;
}


/**
 * @brief      Gets the vertex.
 *
 * @param[in]  id    The identifier
 *
 * @return     The vertex or a null vertex if it is not found.
 */
Vertex & UGraph::getVertex ( int id )
{
	for ( int i=0; i < this->getGraphOrder(); i++ )
		if ( vertices[i].getId() == id ) return vertices[i];

	static Vertex nullVertex = Vertex();
	return (nullVertex);
}

/**
 * @brief      Gets the vertices.
 *
 * @return     The vertices.
 */
std::vector<Vertex> & UGraph::getVertices ()
{
	return vertices;
}

/**
 * @brief      Gets the graph order.
 *
 * @return     The graph order.
 */
int UGraph::getGraphOrder ()
{
	return this->vertices.size();
}

/**
 * @brief      Gets the vertex-induced subgraph.
 *
 * @param[in]  vertices        A vector containing a set of vertices
 * @param      originalGraph   The original graph
 *
 * @return     The vertex induced subgraph corresponding a set
 *             of vertices. 
 */
UGraph UGraph::getVertexInducedSubgraph ( 
	std::vector<Vertex> vertices )
{
	UGraph vertexInducedSubgraph = UGraph();

	// add vertix in a new graph
	for ( unsigned int i=0; i < vertices.size(); i++)
		vertexInducedSubgraph.addVertex( vertices[i] );

	// add coresponding edges
	std::vector<Vertex> adjList;
	for ( unsigned int i=0; i < vertices.size(); i++)
	{
		adjList = vertices[i].getAdjList();
		for ( unsigned int j=0; j < adjList.size(); j++ )
		{
			if ( vertexInducedSubgraph.getVertex( adjList[j].getId() ).getDegree() != -1 )
				vertexInducedSubgraph.getVertex( vertices[i].getId() ).addEdge(adjList[j]);
		}
	}

	return vertexInducedSubgraph;
}

/**
 * @brief      Gets the adj list.
 *
 * @param[in]  vertex  The vertex
 *
 * @return     The adj list.
 */
std::vector<Vertex> UGraph::getAdjList ( Vertex vertex )
{
	std::vector<Vertex> adjList;
	for (unsigned int i=0; i < this->vertices.size(); i++)
	{
		auto aux = vertices[i].getAdjList();
		for (unsigned int j=0; j < aux.size(); j++)
		{
			if ( aux[j].getId() == vertex.getId())
				adjList.push_back(vertices[i]);
		}
	}

	return adjList;
}

/**
 * @brief      Gets the edge weight.
 *
 * @param[in]  source  The source
 * @param[in]  sink    The sink
 *
 * @return     The edge weight, -1 if not found.
 */
int UGraph::getEdgeWeight ( Vertex source, Vertex sink )
{
	for (unsigned int i=0; i < this->edges.size(); i++)
	{
		if ( (edges[i].getSource().getId() == source.getId() and
		      edges[i].getSink().getId() == sink.getId()) or
		     (edges[i].getSource().getId() == sink.getId() and
		      edges[i].getSink().getId() == source.getId()) )
		{
			return edges[i].getWeight();
		}
	}
	return -1;
}

/**
 * @brief      Returns a string representation of the object for 
 *             visualization of Dijkstra's algorithm .
 *
 * @return     String representation of the object.
 */
std::string UGraph::toStringDijkstra ()
{
	std::string value = "";
	value += "(Vertice)[ Rot | value ]\n";
	for (unsigned int it=0; it < vertices.size(); it++)
	{
		value+= "(";
		value+= std::to_string(vertices[it].getId()) + ")[ ";
		value+= std::to_string(vertices[it].getLabeledBy()) + " | ";
		value+= std::to_string(vertices[it].getPathWeight()) + " ]\n";
	}

	return value;
}

