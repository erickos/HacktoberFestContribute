#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "classes/UGraph.h"

void removeVertex (std::vector<Vertex> &freeSet, Vertex vertex);
void updateReference (std::vector<Vertex> &freeSet, UGraph &graph);
UGraph dijkstra (UGraph &graph);

#endif