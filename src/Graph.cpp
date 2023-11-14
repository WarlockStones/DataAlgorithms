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
	int xPos = 0;
	int yPos = 0;
	std::string line;
	// TODO: Maybe add several relative paths, test until it finds this file
	std::ifstream myFile(path); // TODO: Fix this relative path!
	if (myFile.is_open())
	{
		while (std::getline (myFile, line))
		{
			// std::cout << line << '\n';
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
		std::cout << "Error: Unable to open file!\n";
	}

	std::cout<<"Graph size = "<<nodes.size()<<'\n';

	std::cout << "The last node has position: " << '\n';
	std::cout << nodes.back().position.x << "x.";
	std::cout << nodes.back().position.y << "y\n";


	/* 2. Connect nodes by immediate neighbors. Up, Down, Left, Right. */
	
	/* I do not think this is a good solution for this node graph, but it makes 
		 sense for our "grid". */
	std::unordered_map<Vector2, GraphNode&> posToNode;

	// Loop and add all nodes to the unordered_map. (Or do it on Node creation)
  // Loop all nodes and check for nodes in all surrounding positions
  //   x+1 x-1 y+1 y-1 all 4 positions.
  // If neighboring node call function to MakeNeighbors(Node& n1, Node& n2)
  
  // Implement traversal
}
