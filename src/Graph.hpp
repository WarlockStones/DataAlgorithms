#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "GraphNode.hpp"

class Graph{
public:
	std::vector<GraphNode> nodes;

	void InitializeGraphFromFile(const char* path);
	void MakeNeighbors(GraphNode* n1, GraphNode* n2);
	void DepthFirstTraversal(); // This runs once. Print all node IDs.
private:
	void DepthFirstTraversal(GraphNode& node, std::vector<int>& discoveredNodesIDs);
};

#endif
