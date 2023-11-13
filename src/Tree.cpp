#include "Tree.h"
#include <iostream>
#include <queue>

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
		std::cout << "The tree is empty. There is nothing to traverse.\n";
		return;
	}
	TraverseInOrder(root);
}

// Delete all nodes
void Tree::Delete()
{
	Delete(root);
}

// Private where we actually do the insertion
void Tree::InsertValue(Node* node, int value)
{
	if (value <= node->value)
	{
    // std::cout<<"Insert: "<<value<<" <= "<<node->value<<". Go left\n";
		if (node->leftChild)
			InsertValue(node->leftChild, value);
		else
			node->leftChild = new Node(value);
	}
	else
	{
    // std::cout<<"Insert: "<<value<<" >= "<<node->value<<". Go right\n";
		if (node->rightChild)
			InsertValue(node->rightChild, value);
		else
			node->rightChild = new Node(value);
	}
}

void Tree::TraverseInOrder(const Node* node)
{
	if (node->leftChild)
		TraverseInOrder(node->leftChild);
	std::cout << node->value << '\n'; // Visit this node
	if (node->rightChild)
		TraverseInOrder(node->rightChild);
}

// Search all at the same level before continuing on to children
void Tree::TraverseBreadthFirst(){
/* Each iteration requires keeping track of which nodes were found on each 
 * level (usually a queue). */

	// Traverse and print the whole level of nodes before going to children
	if (root == nullptr){
		std::cout<<"The tree is empty. There is nothing to traverse.\n";
		return;
	}

	std::queue<Node*> queue;
  
  queue.push(root);
  
  // TODO: Add some sort of visual element. Maybe just when a level is done
  while (!queue.empty()) {
    Node* temp = queue.front(); // First thing added. Pos 1 in queue
    std::cout<<queue.front()->value<<'\n';
    queue.pop();
    
    if (temp->leftChild != nullptr){
			queue.push(temp->leftChild);
		}
		if (temp->rightChild != nullptr) {
			queue.push(temp->rightChild);
		}
	}

	std::cout<<"Traverse Breadth First is done!\n";
}

void Tree::Delete(Node* node)
{
	// It is the parent's responsibility to delete the child if it is a leaf.
	if (node->leftChild)
	{
		if (node->leftChild->IsLeaf())
		{
			std::cout << "Deleting child node with value: " << node->leftChild->value << '\n';
			delete node->leftChild;
			node->leftChild = nullptr;
		}
		else
		{
			Delete(node->leftChild); // Go and try to delete the left child
			return;
		}
	}
	if (node->rightChild)
	{
		if (node->rightChild->IsLeaf())
		{
			std::cout << "Deleting child node with value: " << node->rightChild->value << '\n';
			delete node->rightChild;
			node->rightChild = nullptr;
		}
		else
		{
			Delete(node->rightChild); // Go an try to delete the right child
			return;
		}
	}

	if (node == root)
	{
		std::cout << "Deleting the final root with value: " << node->value << '\n';
		delete node;
		root = nullptr; // So that we can re-create the tree. And have no dangling pointers!
		return; // Stop the recursion
	}

	// We have no children. Restart recursion again from root
	Delete(root);
}
