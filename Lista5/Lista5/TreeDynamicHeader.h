#pragma once
#include "NodeDynamic.cpp"
class TreeDynamic {
private:
	NodeDynamic *root = new NodeDynamic();

public:
	TreeDynamic() {};
	TreeDynamic(NodeDynamic * root) { this->root = root; }
	~TreeDynamic() { delete root; };

	bool moveSubtree(NodeDynamic * parentNode, NodeDynamic * newChildNode);
	NodeDynamic * getRoot() { return root; };
	void printTree();
	bool doBelongToSameTree(NodeDynamic * node1, NodeDynamic * node2);
};