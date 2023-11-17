#include "Measurements.hpp"
#include "Tree.hpp"
#include "Graph.hpp"
#include "Vector2.hpp"
#include "Map.hpp"
#include "HashMap.hpp"

/* TODO:
 * - Fix HashMap Remove function
 * - Test HashMap Measurements. And against std::unordered_map
 * - Add CLI graphics for Graph.
 * - GUI: Change the node we find to another character for the console to print. '@'
	      Or add a PrettyPrint function that shows the iteration. feed it vector of grids to highlight?
 */

int main()
{
	/* HashMap */

	// HashMap Remove bug example
	HashMap hashMap;
	hashMap.Initialize(4);
	hashMap.Insert("Hello", "Hej");
	hashMap.Insert("One", "1");
	hashMap.Insert("Two", "2");
	hashMap.Insert("Three", "3");
	hashMap.Insert("Four", "4");
	hashMap.Insert("Five", "5");
	hashMap.Insert("Six", "6");
	hashMap.Remove("Six");
	hashMap.Remove("Five");
	hashMap.Remove("Four");


	return 0; // --------------------------------------------------------------
	/* Graph */
	Graph graph;
	graph.InitializeGraphFromFile("../data/GraphNodes.txt");
	std::cout << "Start Graph Depth First Traversal\n";
	graph.DepthFirstTraversalPrint();
	std::cout << '\n';

	std::cout << "--- Breadth first search for ID ---\n";
	GraphNode* find = graph.BreadthFirstSearch(-1);
	if (find != nullptr)
	{
		std::cout << "Graph Node found! ID = "<<find->id<<". Pos = " << find->position.x << "." << find->position.y << '\n';
	}
	else std::cout << "BreadthFirstSearch returned nullptr\n";

	std::cout << "--- Breadth first search for Pos ---\n";
	const Vector2 v(8, 0);
	find = graph.BreadthFirstSearch(v);
	if (find != nullptr)
	{
		std::cout << "Graph Node found! ID = "<<find->id<<". Pos = " << find->position.x << "." << find->position.y << '\n';
	}
	else std::cout << ("BreadthFirstSearch returned nullptr\n");

	return 0; // --------------------------------------------------------------
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
