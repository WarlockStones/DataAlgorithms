#include "Node.hpp"

bool Node::IsLeaf()
{
	if (leftChild == nullptr && rightChild == nullptr)
		return true;
	else
		return false;
}

