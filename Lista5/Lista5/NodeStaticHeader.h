#pragma once
#include <iostream>
#include <vector>

class NodeStatic {

private:
	std::vector<NodeStatic> children;
	NodeStatic *parentNode;
	int val;

public:
	NodeStatic() { val = 0; parentNode = NULL; };
	NodeStatic(NodeStatic * parent) { val = 0; parentNode = parent; };
	~NodeStatic();

	void setValue(int newVal) { val = newVal; };
	int getValue() { return val; };

	int getChildrenNumber() { return(children.size()); };
	void addNewChild();
	void addNewChild(NodeStatic & newChild);
	NodeStatic *getChild(int childOffset);
	NodeStatic *getParent() { return parentNode; };
	bool deleteChild(NodeStatic * child);
	
	void setParent(NodeStatic * newParent) { parentNode = newParent; };

	void print() { std::cout << " " << val; };
	void printAllBelow();
	void printUp();

	NodeStatic & operator=(NodeStatic & node);

};