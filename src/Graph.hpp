#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <unordered_set>
#include "GraphNode.hpp"

class Graph{
public:
	// not a vector. I do not want to loop it. Each ID is unique, a set works well
	std::vector<GraphNode> nodes;

	void InitializeGraphFromFile(const char* path);
	void MakeNeighbors(GraphNode* n1, GraphNode* n2);
	void DepthFirstTraversal(); // This runs once. Print all node IDs.
	void BreadthFirstSearch(int id);
	void BreadthFirstSearch(Vector2 pos);
private:
	void DepthFirstTraversal(GraphNode& node, std::unordered_set<int>& discoveredNodesIDs);
	void BreadthFirstSearch(std::vector<GraphNode*>& nodesToVisit, std::unordered_set<int>& visitedIDs, int idToFind);
	void BreadthFirstSearch(std::vector<GraphNode*>& nodesToVisit, std::unordered_set<int>& visitedIDs, Vector2 posToFind);
};

#endif
