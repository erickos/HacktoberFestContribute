#ifndef _RECONNECT_H_
#define _RECONNECT_H_

#include "classes/UGraph.h"
#include "classes/DFSTree.h"

Edge reconnect(UGraph graph, int bridge);

// based in: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/components.html
int relatedComponent (UGraph &graph, int *components);

// based in: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/components.html
void recursiveCC (UGraph &graph, int *componets, Vertex vertex, int id);

#endif