#ifndef NODE_H
#define NODE_H

class Node {
public:
	// To use the same class (ex. Node in Node) it must be a pointer. Else it will complain "Class is incomplete"
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	int value{};

	// Check if this node does not have any children
	bool IsLeaf();

	Node(int _value)
	{
		this->value = _value;
	}
	~Node() = default;
};

#endif
