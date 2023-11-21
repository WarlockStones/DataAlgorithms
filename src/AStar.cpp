#include "AStar.hpp"
#include <deque>

/*
std::vector<GraphNode> AStar::ReconstructPath(std::map<GraphNode, GraphNode>& cameFrom, GraphNode& current)
{
	std::deque<GraphNode> path; // To add to front we shouldn't use a vector
	path.push_back(current);


	// CameFrom.KEYS I ONLY NEED KEYS! I must compare KEYS!
	// Compilation error. GraphNode has no '<' operator
	cameFrom.contains(current);

	// TODO: Lots of copying. Optimize later.
	std::vector<GraphNode> v;
	for (GraphNode node : path)
	{
		// Will this vector be backwards?
		v.push_back(node);
	}
	return v;
}
*/

/*
int AStar::Heuristic(GraphNode from)
{
	// Manhattan distance
	return std::abs(from.position.x - goal.position.x) + std::abs(from.position.y - goal.position.y);
}
*/

/*
float AStar::D(GraphNode* n1, GraphNode* n2)
{
	// Calculate distance between to vectors. But it is a grid, it will all be the same?
	// sqrt( (n1.pos.x - n2.pos.x)^2 + (n1.pos.y - n2.pos.y)^2 )
	return std::sqrt(std::pow(n1->position.x - n2->position.x, 2) +
		std::pow(n1->position.y - n2->position.y, 2));
}
*/

// The AStar loop
/*
void AStar::Pathfind(Graph graph, GraphNode startNode, GraphNode goalNode)
{
	openSet.insert(startNode);
	while (!openSet.empty())
	{
		GraphNode temp = *openSet.begin(); // Unnecessary copying
		GraphNode* current = &temp;
		// GraphNode* current = &(*openSet.begin()); // How to initialize non-const value from const value?
		if (current->position == goalNode.position) // TODO: Overload ==
		{
			std::vector<GraphNode> rPath = ReconstructPath(cameFrom, *current);
			std::cout << "Found a path! \n";
			for (auto node : rPath)
			{
				std::cout << node.id << "|pos" << node.position.x << '.' << node.position.y << ' ';
			}
		}
		openSet.erase(openSet.find(*current));

		for (auto neighbor  : current->neighbors)
		{
			// TODO: gScore store pointers instead?
			// TODO: Fix conversions. Floats or Ints? Pick one.
			float tentative_gScore = gScore[*current] + D(current, neighbor);
			if (tentative_gScore < gScore[*neighbor])
			{
				cameFrom[*neighbor] = *current;
				gScore[*neighbor] = tentative_gScore;
				fScore[*neighbor] = tentative_gScore + Heuristic(*neighbor);
				if (!openSet.contains(*neighbor))
				{
					openSet.insert(*neighbor);
				}
			}
		}
	}

	// OpenSet is empty. We did not find a path. return Failure
	std::cout << "Could not find any valid paths\n";
}
*/
