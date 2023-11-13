#ifndef NODE_H
#define NODE_H

struct Node {
	// In C++, to use the same class (ex. Node in Node) it must be a pointer. Else it will complain "Class is incomplete"
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	int value{};
	Node(int _value)
	{
		this->value = _value;
	}
	~Node() = default;
};

#endif