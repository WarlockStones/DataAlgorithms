#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "GraphNode.hpp"

class Graph{
public:
	std::vector<GraphNode> nodes;
  
  void InitializeGraphFromFile(const char* path);
};

#endif
