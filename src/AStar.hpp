#ifndef ASTAR_H
#define ASTAR_H
#include "GraphNode.hpp"
#include "Graph.hpp"
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <cmath>

class AStar {
public:
	AStar();

	GraphNode goal;
	std::set<GraphNode> openSet; // Discovered nodes
	std::map<GraphNode, GraphNode> cameFrom; //
	std::map<GraphNode, int> gScore;
	std::map<GraphNode, int> fScore; // From a given node to the goal. To see which nodes to look at next, avoid back-tracing

	std::vector<GraphNode> ReconstructPath(std::map<GraphNode, GraphNode>& cameFrom, GraphNode& current);
	int Heuristic(GraphNode from);
	float D(GraphNode* n1, GraphNode* n2); // Return distance / weight between two nodes

	// Traverse and print
	void Pathfind(Graph graph, GraphNode startNode, GraphNode goalNode);
};

#endif // !ASTAR_H
