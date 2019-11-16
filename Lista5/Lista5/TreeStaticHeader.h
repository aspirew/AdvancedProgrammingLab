#pragma once
#include "NodeStatic.cpp"
class TreeStatic {
private:
	NodeStatic root;
public:
	TreeStatic() {};
	TreeStatic(NodeStatic root) { this->root = root; }
	~TreeStatic() {};

	bool moveSubtree(NodeStatic * parentNode, NodeStatic * newChildNode);
	NodeStatic *getRoot() { return (&root); }
	void printTree();
};