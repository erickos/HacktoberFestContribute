#ifndef _DFS_H_
#define _DFS_H_

#include <stack>
#include <string>
#include "classes/UGraph.h"
#include "classes/DFSTree.h"

DFSTree dfs ( UGraph graph );
void recursiveDfs ( Vertex vertex, std::stack<Vertex> &stack, DFSTree &tree, UGraph & graph );

#endif