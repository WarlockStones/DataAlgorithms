#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include "Vector2.hpp"
#include <vector>

struct GraphNode{
	Vector2 position{};
	int id{};
	// Now that it is pointers I must remember them up if I delete a node
	std::vector<GraphNode*> neighbors{}; // Just do neighborIDs to decouple and then access through a find function?
	GraphNode() = default;
	GraphNode(Vector2 _pos, int _id)
	{
		this->position = _pos;
		this->id = _id;
	}
};

#endif