#pragma once
#include "NodeDynamic.cpp"
class TreeDynamic {
private:
	NodeDynamic *root;

public:
	TreeDynamic() {};
	TreeDynamic(NodeDynamic * root) { this->root = root; }
	~TreeDynamic() {};

	bool moveSubtree(NodeDynamic * parentNode, NodeDynamic * newChildNode);
	NodeDynamic * getRoot() { return root; };
	void printTree();
};