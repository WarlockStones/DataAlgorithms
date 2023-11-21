#include "Graph.hpp"
#include <string>
#include <fstream>
#include <iostream>

#include "GraphGUI.hpp"

void Graph::InitializeGraphFromFile(const char* path)
{
	// This will not really be a node graph. More like a grid
	// Parse the text file and create nodes. On 'o' create a node. On 'X' don't do anything
	int graphNodeIds = 0;
	int xPos = 0;
	int yPos = 0;
	std::string line;
	std::ifstream myFile(path);
	if (myFile.is_open())
	{
		while (std::getline(myFile, line))
		{
			// Parse and create nodes
			for (char c : line)
			{
				if (c == 'o')
				{
					// What to do with data management? Allocating on the heap is slow?
					GraphNode* gNode = new GraphNode({xPos, yPos}, graphNodeIds);
					nodes.push_back(*gNode);
					++graphNodeIds;
				}
				++xPos;
			}
			// New line
			xPos = 0;
			++yPos;
		}
		myFile.close();
	}
	else
	{
		std::cout << "Error: Unable to open file! '" << path << "'\n";
		return;
	}

	/* Connect nodes by immediate neighbors. Up, Down, Left, Right. */
	for (std::size_t i = 0; i < nodes.size(); ++i)
	{
		const Vector2 nodePos = nodes[i].position;

		const Vector2 upNeighborPos = {nodePos.x, nodePos.y - 1};
		const Vector2 rightNeighborPos = {nodePos.x + 1, nodePos.y};
		const Vector2 downNeighborPos = {nodePos.x, nodePos.y + 1};
		const Vector2 leftNeighborPos = {nodePos.x - 1, nodePos.y};

		// Nested for-loop. Do not bother with map now. Optimization wont be necessary. This runs once
		for (std::size_t n = i + 1; n < nodes.size(); ++n)
		{
			if (nodes[n].position == upNeighborPos)
				MakeNeighbors(&nodes[i], &nodes[n]);

			else if (nodes[n].position == rightNeighborPos)
				MakeNeighbors(&nodes[i], &nodes[n]);

			else if (nodes[n].position == downNeighborPos)
				MakeNeighbors(&nodes[i], &nodes[n]);

			else if (nodes[n].position == leftNeighborPos)
				MakeNeighbors(&nodes[i], &nodes[n]);
		}
	}
}

void Graph::MakeNeighbors(GraphNode* n1, GraphNode* n2)
{
	// Check if they are already neighbors
	for (auto neighbor : n1->neighbors)
	{
		if (neighbor == n1)
		{
			return;
		}
	}

	n1->neighbors.push_back(n2);
	n2->neighbors.push_back(n1);
}

void Graph::DepthFirstTraversal()
{
	// Here I initialize a set which I then pass as a reference.
	// QUESTION: When will the the stack memory be de-allocated? What is the life-time of the set?
	std::unordered_set<int> discoveredNodeIDs;
	DepthFirstTraversal(nodes[0], discoveredNodeIDs);
}


void Graph::DepthFirstTraversal(GraphNode& node, std::unordered_set<int>& discoveredNodeIDs)
{
	discoveredNodeIDs.insert(node.id);
	if (GraphGUI::enabled) GraphGUI::PrintTraversal(node.position); // Is accessing static memory slow?

	for (auto neighbor : node.neighbors)
	{
		if (auto search = discoveredNodeIDs.find(neighbor->id); search != discoveredNodeIDs.end())
		{
		}
		else
		{
			DepthFirstTraversal(*neighbor, discoveredNodeIDs);
		}
	}
}

static int breadthIterations = 0;

// Changed from recursion to while loops for return value
GraphNode* Graph::BreadthFirstSearch(int idToFind)
{
	std::vector<GraphNode*> nodesToVisit;
	std::unordered_set<int> visitedIDs;
	nodesToVisit.push_back(&nodes.front());
	breadthIterations = 0;

	std::vector<GraphNode*> newNodesToVisit;
	while (!nodesToVisit.empty())
	{
		++breadthIterations;
		for (auto node : nodesToVisit)
		{
			if (node->id == idToFind)
			{
				return node;
			}
			visitedIDs.insert(node->id);

			for (auto neighbor : node->neighbors)
			{
				if (auto search = visitedIDs.find(neighbor->id); search == visitedIDs.end())
				{
					// If we have not visited the neighbor
					newNodesToVisit.push_back(neighbor);
				}
			}
		}

		nodesToVisit = newNodesToVisit;
		newNodesToVisit.clear();
	}

	return nullptr;
}

// There is a lot of repetition in these two functions. Find smarter solution?
GraphNode* Graph::BreadthFirstSearch(Vector2 posToFind)
{
	std::vector<GraphNode*> nodesToVisit;
	std::unordered_set<int> visitedIDs;
	nodesToVisit.push_back(&nodes.front());
	breadthIterations = 0;

	std::vector<GraphNode*> newNodesToVisit;
	while (!nodesToVisit.empty())
	{
		++breadthIterations;
		for (auto node : nodesToVisit)
		{
			if (node->position == posToFind)
			{
				return node;
			}
			visitedIDs.insert(node->id);

			for (auto neighbor : node->neighbors)
			{
				if (auto search = visitedIDs.find(neighbor->id); search == visitedIDs.end())
				{
					// If we have not visited the neighbor
					newNodesToVisit.push_back(neighbor);
				}
			}
		}

		nodesToVisit = newNodesToVisit;
		newNodesToVisit.clear();
	}

	return nullptr;
}
