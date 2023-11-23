#include "Measurements.hpp"
#include "Tree.hpp"
#include "Graph.hpp"
#include "Vector2.hpp"
#include "Map.hpp"
#include "HashMap.hpp"
#include "GraphGUI.hpp"
#include "AStar.hpp"
#include "Sort.hpp"

/* TODO:
 * - Clean up all types. Pointers? Reference? Sort out when and where to use what
 * - Update GraphGUI::enabled implementation (Do this before adding more prints)
 * - Add GUI to A*
 * LOW PRIORITY:
 * - Fix HashMap Remove function
 * - Create events for when each traversal is done. (To reset GUI)
 */

int main()
{
	Sort sort;
	srand(static_cast<unsigned>(time(nullptr)));
	const int ARR_MAX = 50000;

	int unsortedArray[ARR_MAX];

	for (int i = 0; i < ARR_MAX; ++i)
	{
		unsortedArray[i] = rand() % 100;
	}

	for (int i : unsortedArray)
		std::cout << i << ' ';
	std::cout << '\n';

	// Copy array
	std::cout << "Copy array: \n";
	int arrayToSort[ARR_MAX];
	for (int i = 0; i < ARR_MAX; ++i)
	{
		arrayToSort[i] = unsortedArray[i];
	}

	for (int i = 0; i < 10; ++i)
		std::cout << arrayToSort[i] << ' ';
	std::cout << "...\n";

	int workingArray[ARR_MAX];
	Measurements measure;
	for (int i = 0; i < 10; ++i)
	{
		measure.StartMeasurement();
		sort.BottomUpMergeSort(arrayToSort, workingArray, ARR_MAX);
		measure.EndMeasurement();

		// Reset arrays:
		for (int i = 0; i < ARR_MAX; ++i)
		{
			arrayToSort[i] = unsortedArray[i];
		}
		for (int i = 0; i < ARR_MAX; ++i)
		{
			workingArray[i] = NULL;
		}
	}
	std::cout << "Results for my MergeSort\n";
	measure.PrintResults();
	measure.ClearResults();

	std::cout << "'\n '\n Now to test std:: !\n";

	int* pLast = (int*)(&arrayToSort + 1) - 1; // Tested and this works!

	for (int i = 0; i < 10; ++i)
	{
		measure.StartMeasurement();
		// std::stable_sort(arrayToSort, pLast);
		std::sort(arrayToSort, pLast);
		measure.EndMeasurement();

		// Reset arrays:
		for (int i = 0; i < ARR_MAX; ++i)
		{
			arrayToSort[i] = unsortedArray[i];
		}
		for (int i = 0; i < ARR_MAX; ++i)
		{
			workingArray[i] = NULL;
		}
	}

	measure.PrintResults();
	measure.ClearResults();




	// std::sort unstable IntroSort algorithm. Hybrid of Quicksort, Heapsort and Insertion Sort.
	
	/*
	for (int i = 0; i < 10; ++i)
	{
		measure.StartMeasurement();
		std::sort(arrayToSort, arrayToSort + ARR_MAX);
		measure.EndMeasurement();

		// Reset arrays:
		for (int i = 0; i < ARR_MAX; ++i)
		{
			arrayToSort[i] = unsortedArray[i];
		}
		for (int i = 0; i < ARR_MAX; ++i)
		{
			workingArray[i] = NULL;
		}
	}
	*/


	// ASTAR ---------------------------------------------------------------------
	return 0;
	GraphGUI::enabled = true;

	GraphGUI::Initialize("../data/GraphNodes.txt");
	GraphGUI::ReplaceChar('o', '.');

	Graph g;
	g.InitializeGraphFromFile("../data/GraphNodes.txt");

	g.DepthFirstTraversal(); 

	std::cout << "BreadthFirstSearch -----------\n";

	GraphNode* s = g.BreadthFirstSearch({ 1, 0 });
    GraphNode* e = g.BreadthFirstSearch({ 7, 6 });
	if (s != nullptr)
	{
		std::cout << "S.id = " << s->id << '\n';
	}
	if (e != nullptr)
	{
		std::cout << "E.id = " << e->id << '\n';
	}

	std::cout << "Astar -----------\n";
	AStar astar;
	astar.Pathfind(g, *s, *e);

	return 0; // --------------------------------------------------------------
	/* HashMap */
	// HashMap Remove bug example. Remove is currently bugged, this demonstrates how
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
	graph.DepthFirstTraversal();
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
