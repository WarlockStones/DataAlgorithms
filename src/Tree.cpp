#include "Tree.h"
#include <iostream>

/* Reference could work if we already have data allocated. But in this case ptrs works
 * better because we can easily allocate new data on the heap with each node creation */

// Public that we just pass value and checks for root and starts recursion
void Tree::InsertValue(int value)
{
	if (root == nullptr)
	{
		root = new Node(value);
		return;
	}
	InsertValue(root, value);
}
// Public that starts the recursion at root
void Tree::TraverseInOrder()
{
	if (root == nullptr)
	{
		std::cout << "The tree is empty.\n";
		return;
	}
	TraverseInOrder(root);
}

// Private where we actually do the insertion
void Tree::InsertValue(Node* node, int value)
{
	if (value <= node->value)
	{
		if (node->leftChild)
			InsertValue(node->leftChild, value);
		else
			node->leftChild = new Node(value);
	}
	else
	{
		if (node->rightChild)
			InsertValue(node->rightChild, value);
		else
			node->rightChild = new Node(value);
	}
}

void Tree::TraverseInOrder(Node* node)
{
	if (node->leftChild)
		TraverseInOrder(node->leftChild);
	std::cout << node->value << '\n'; // visit this node
	if (node->rightChild)
		TraverseInOrder(node->rightChild);
}

