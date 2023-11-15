#include "Graph.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

void Graph::InitializeGraphFromFile(const char* path){
	// This will not really be a node graph. More like a grid
	// 1. Parse the text file and create nodes
	// On 'o' Create node on X don't create anything.
	int graphNodeIds = 0;
	float xPos = 0;
	float yPos = 0;
	std::string line;
	// TODO: Maybe add several relative paths, test until it finds this file
	std::ifstream myFile(path); // TODO: Fix this relative path!
	if (myFile.is_open())
	{
		while (std::getline (myFile, line))
		{
			// Parse and create nodes
			for (char c : line)
			{
				std::cout << c;
				if (c == 'o')
				{
					// What to do with data management? At the moment I just allocated onto the heap.
					GraphNode* gNode = new GraphNode({ xPos, yPos }, graphNodeIds);
					nodes.push_back(*gNode);
				}
				++xPos;
			}
			// New line
			xPos = 0;
			++yPos;
			std::cout << '\n'; // 
		}
		myFile.close();
	}
	else
	{
		std::cout << "Error: Unable to open file! '"<<path<<"'\n";
		return;
	}

	std::cout<<"Graph size = "<<nodes.size()<<'\n';
	std::cout << "The last node has position: " << '\n';
	std::cout << nodes.back().position.x << "x.";
	std::cout << nodes.back().position.y << "y\n";


	/* 2. Connect nodes by immediate neighbors. Up, Down, Left, Right. */
	// Nested for-loop. Do not bother with map now. The optimization wont be necessary
	for (std::size_t i = 0; i < nodes.size(); ++i)
	{
		const Vector2 nodePos = nodes[i].position;
		const Vector2 upNeighborPos = { nodePos.x, nodePos.y - 1 };
		const Vector2 rightNeighborPos = { nodePos.x + 1, nodePos.y };
		const Vector2 downNeighborPos = { nodePos.x, nodePos.y + 1 };
		const Vector2 leftNeighborPos = { nodePos.x - 1, nodePos.y };
		for (std::size_t n = i+1; n < nodes.size(); ++n)
		{
			if (nodes[n].position == upNeighborPos)
			{
				MakeNeighbors(&nodes[i], &nodes[n]);
			}
			else if (nodes[n].position == rightNeighborPos)
			{
				MakeNeighbors(&nodes[i], &nodes[n]);
			}
			else if (nodes[n].position == downNeighborPos)
			{
				MakeNeighbors(&nodes[i], &nodes[n]);
			}
			else if (nodes[n].position == leftNeighborPos)
			{
				MakeNeighbors(&nodes[i], &nodes[n]);
			}

			/*
			switch (nodes[n].position)
			{
			case upNeighborPos:
				std::cout << "Neighbor found!\n";
				break;
			case rightNeighborPos:
				std::cout << "Neighbor found!\n";
				break;
			case downNeighborPos:
				std::cout << "Neighbor found!\n";
				// Make neighbor!
				break;
			case leftNeighborPos:
				std::cout << "Neighbor found!\n";
				break;
			default:
				break;
			}
			*/
		}
	}

	/* I do not think this is a good solution for this node graph, but it makes 
		 sense for our "grid". */

	// Loop and add all nodes to the unordered_map. (Or do it on Node creation)
	// Loop all nodes and check for nodes in all surrounding positions
	//   x+1 x-1 y+1 y-1 all 4 positions.
	// If neighboring node call function to MakeNeighbors(Node& n1, Node& n2)
	
	// Implement traversal
}

void Graph::MakeNeighbors(GraphNode* n1, GraphNode* n2)
{
	// Check if they are already neighbors
	for (auto neighbor : n1->neighbors)
	{
		if (neighbor == n1)
		{
			// They are neighbors just return
			return;
		}
	}

	// n1 and n2 are not neighbors. Make them neighbors
	n1->neighbors.push_back(n2);
	n2->neighbors.push_back(n1);
}

void Graph::DepthFirstTraversal()
{
	// Here I initialize a vector which I then pass as a reference.
	// QUESTION: When will the the stack memory be de-allocated? What is the life-time of the object?
	std::vector<int> discoveredNodeIDs;
	DepthFirstTraversal(nodes[0], discoveredNodeIDs);
}



static int testInt = 0;
void Graph::DepthFirstTraversal(GraphNode& node, std::vector<int>& discoveredNodeIDs)
{
	discoveredNodeIDs.push_back(node.id); // Test!
	testInt++;
	std::cout << testInt<<' ';
	if (testInt >= nodes.size()) return;
	DepthFirstTraversal(nodes[testInt],discoveredNodeIDs);
}
