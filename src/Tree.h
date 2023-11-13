#ifndef TREE_H
#define TREE_H
#include "Node.h"


// TODO: Add a "Find" function
// Indices seems rather pointless, what is tree[5]? like in what branch even is that? 
class Tree {
public:
	void InsertValue(int value);
	void TraverseInOrder();
	void Delete();
private:
	Node* root = nullptr;
	void InsertValue(Node* node, int value);
	void TraverseInOrder(Node* node);
	void Delete(Node* node);
};

#endif