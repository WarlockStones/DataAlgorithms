#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <unordered_set>
#include "GraphNode.hpp"

class Graph{
public:
	std::vector<GraphNode> nodes;

	void InitializeGraphFromFile(const char* path);
	void MakeNeighbors(GraphNode* n1, GraphNode* n2);
	void DepthFirstTraversalPrint(); // Print all IDs
	GraphNode* BreadthFirstSearch(int id);
	GraphNode* BreadthFirstSearch(Vector2 pos);
private:
	void DepthFirstTraversalPrint(GraphNode& node, std::unordered_set<int>& discoveredNodesIDs);
};

#endif
