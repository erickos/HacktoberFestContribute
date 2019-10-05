#ifndef _TARJAN_H_
#define _TARJAN_H_

#include "algorithms/dfs.h"
#include <vector>

std::vector<Vertex> UGraphBridges ( UGraph graph );
int calcLowpt ( DFSTree &tree, int index );
bool isBridge (DFSTree &tree, std::vector<int> &lowpt, Vertex vertex);
std::vector<int> calcAllLowpt( DFSTree &tree );

#endif