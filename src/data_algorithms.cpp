#include <fstream>
#include "Measurements.hpp"
#include "Tree.h"
#include "Graph.hpp"
#include "Vector2.hpp"

int main()
{
	// Measurements measure;
	// measure.MeasureBinarySearch();


	/* Graph */

	Graph graph;
	graph.nodes = {
	};
	Vector2 v;
	v.x = 1;
	v.y = 2;
	std::cout << "v's x.y: " << v.x << '.' << v.y << '\n';

	// This will not really be a node graph. More like a grid
	// 1. Parse the text file and create nodes
	// On 'o' Create node on X don't create anything.
	int graphNodeIds = 0;
	int xPos = 0;
	int yPos = 0;
	std::string line;
	std::ifstream myFile("../../../data/GraphNodes.txt"); // TODO: Fix this relative path!
	if (myFile.is_open())
	{
		while (std::getline (myFile, line))
		{
			// std::cout << line << '\n';
			// Parse and create nodes
			for (char c : line)
			{
				std::cout << c << ".";
				if (c == 'o')
				{
					// What to do with data management? At the moment I just allocated onto the heap.
					GraphNode* gNode = new GraphNode({ xPos, yPos }, graphNodeIds);
					graph.nodes.push_back(*gNode);
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

	std::cout<<"Graph size = "<<graph.nodes.size()<<'\n';

	std::cout << "The last node has position: " << '\n';
	std::cout << graph.nodes.back().position.x << "x.";
	std::cout << graph.nodes.back().position.y << "y\n";


	// 2. Connect the nodes by looking for immediate neighbors


	return 0;
	Tree tree;

	/*
		   8
		 /   \
		3     10
	   / \      \
	  1   6      14
		 / \    /
		4   7  13
	   /
	  4
	*/
	tree.InsertValue(8); // Root

	// Right sub-nodes
	tree.InsertValue(10);
	tree.InsertValue(14);
	tree.InsertValue(13);

	// Left sub-nodes
	tree.InsertValue(3);
	tree.InsertValue(1);
	tree.InsertValue(6);
	tree.InsertValue(4);
	tree.InsertValue(7);
	tree.InsertValue(4);

	tree.TraverseBreadthFirst();

	return 0;
}
