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

void Tree::Delete()
{
	Delete(root);
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

// Delete all nodes
void Tree::Delete(Node* node)
{
	// It is the parent's responsibility to delete the child if it is a leaf.
	if (node->leftChild && node->leftChild->IsLeaf())
	{
		std::cout << "Deleting child node with value: " << node->leftChild->value<<'\n';
		delete node->leftChild;
		node->leftChild = nullptr;
	}
	if (node->rightChild && node->rightChild->IsLeaf())
	{
		std::cout << "Deleting child node with value: " << node->rightChild->value<<'\n';
		delete node->rightChild;
		node->rightChild = nullptr;
	}

	// Recursively go deeper into the tree
	// TODO: Clean this code up. These checks seems a bit redundant but it works!
	if(node->leftChild)
	{
		// Go try to delete leftChild
		Delete(node->leftChild);
		return;
	}
	if(node->rightChild)
	{
		// Go try to delete rightChild
		Delete(node->rightChild);
		return;
	}

	if (node == root)
	{
		std::cout << "Deleting the final root node that has value "<<node->value<<'\n';
		delete node;
		root = nullptr; // So that we can re-create the tree. And have no dangling pointers!
		return; // Stop the recursion
	}

	// We have no children. Restart recursion
	Delete(root);
}
