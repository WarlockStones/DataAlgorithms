#ifndef TREE_H
#define TREE_H
#include "Node.h"
// TODO: Add a "Find" function

// Indices seems rather pointless, what is tree[5]? like in what branch even is that? 

/* Binary Search Tree. The value of each node is greater than all the values in
 * the respective node's left subtree and less than the ones in its right subtree. */
class Tree {
public:
	void InsertValue(int value);
	void TraverseInOrder();
	void TraverseBreadthFirst();
	void Delete();
private:
	Node* root = nullptr;
	void InsertValue(Node* node, int value);
	void TraverseInOrder(const Node* node);
	void Delete(Node* node);
};

#endif
