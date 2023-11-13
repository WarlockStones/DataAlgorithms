#ifndef TREE_H
#define TREE_H
#include "Node.h"


// TODO: Add a "Find" function.
// TODO: Add a destroy function because now we are never deleting nodes allocated on the heap
// Indices seems rather pointless, what is tree[5]? like in what branch even is that? 
class Tree {
public:
	void InsertValue(int value);
	void TraverseInOrder();
	Node* root = nullptr;
private:
	void InsertValue(Node* node, int value);
	void TraverseInOrder(Node* node);
};

#endif