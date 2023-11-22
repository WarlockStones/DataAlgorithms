#include "AStar.hpp"
#include <deque>
#include <limits>


std::deque<GraphNode*> AStar::ReconstructPath(std::map<GraphNode*, GraphNode*>& cameFrom, GraphNode* current)
{
	// Deque to add to front
	std::deque<GraphNode*> totalPath{};

	totalPath.push_front(current);

	while (cameFrom.contains(current))
	{
		current = cameFrom[current];
		totalPath.push_front(current);
	}
	return totalPath;
}

int AStar::Heuristic(GraphNode& from)
{
	// Manhattan distance
	return std::abs(from.position.x - goal->position.x) + std::abs(from.position.y - goal->position.y);
}

// GraphNodes are sorted on a grid using integers. The return value will always be an integer
// The distance to every neighbor for every node is 1. This function is rather useless in this implementation
int AStar::D(GraphNode* n1, GraphNode* n2)
{
	// Calculate distance between to vectors. But it is a grid, neighbors will always be 1 distance away
	// sqrt( (n1.pos.x - n2.pos.x)^2 + (n1.pos.y - n2.pos.y)^2 )

	return std::sqrt(std::pow(n1->position.x - n2->position.x, 2) +
		std::pow(n1->position.y - n2->position.y, 2));
}

// The AStar loop
void AStar::Pathfind(Graph& graph, GraphNode& startNode, GraphNode& goalNode)
{
	this->goal = &goalNode;
	gScore[&startNode] = 0;
	fScore[&startNode] = Heuristic(startNode);

	openSet.insert(&startNode);
	while (!openSet.empty())
	{
		GraphNode* current = *openSet.begin();
		if (current->position == goalNode.position) // TODO: Overload ==
		{
			//TODO GUI Print Path
			std::deque<GraphNode*> rPath = ReconstructPath(cameFrom, current);
			std::cout << "Found a path! \n";
			for (auto node : rPath)
			{
				std::cout <<"id: "<<node->id << " | pos: " << node->position.x << '.' << node->position.y << '\n';
			}
			return;
		}
		openSet.erase(openSet.find(current));

		for (auto neighbor  : current->neighbors)
		{
			/* Populate the maps */
			if (!gScore.contains(current))
			{
				gScore[current] = std::numeric_limits<int>::max();
			}
			if (!gScore.contains(neighbor))
			{
				gScore[neighbor] = std::numeric_limits<int>::max();
			}
			if (!fScore.contains(current))
			{
				fScore[current] = std::numeric_limits<int>::max();
			}
			if (!fScore.contains(neighbor))
			{
				fScore[neighbor] = std::numeric_limits<int>::max();
			}

			int tentative_gScore = gScore[current] + D(current, neighbor);
			if (tentative_gScore < gScore[neighbor])
			{
				cameFrom[neighbor] = current;
				gScore[neighbor] = tentative_gScore;
				fScore[neighbor] = tentative_gScore + Heuristic(*neighbor);
				if (!openSet.contains(neighbor))
				{
					openSet.insert(neighbor);
				}
			}
		}
	}

	// OpenSet is empty. We did not find a path. return Failure
	std::cout << "Could not find any valid paths\n";
}
