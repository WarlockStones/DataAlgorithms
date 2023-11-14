#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include "Vector2.hpp"
#include <vector>

struct GraphNode{
	Vector2 position{};
	int id{};
	std::vector<GraphNode> neighbors{};
	GraphNode(Vector2 _pos, int _id)
	{
		this->position = _pos;
		this->id = _id;
	}
};

#endif