#pragma once
#include "NodeDynamic.cpp"

template <typename T>
class TreeDynamic {
private:
	T *root = new T();

public:
	TreeDynamic() {};
	TreeDynamic(T * root) { this->root = root; }
	~TreeDynamic() { delete root; };

	bool moveSubtree(T * parentNode, T * newChildNode);
	T * getRoot() { return root; };
	void printTree();
	bool doBelongToSameTree(T * node1, T * node2);

	std::string getKnownType();

	int getNumberOfLeaves();
};