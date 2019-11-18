#pragma once
#include "NodeStatic.cpp"
class TreeStatic{
private:
	NodeStatic root;
	NodeStatic getRoot(NodeStatic * node);
public:
	TreeStatic() {};
	~TreeStatic() {};

	bool moveSubtree(NodeStatic * parentNode, NodeStatic * newChildNode);
	NodeStatic *getRoot() { return (&root); }
	void printTree();

	bool doBelongToSameTree(NodeStatic * node1, NodeStatic * node2);
};