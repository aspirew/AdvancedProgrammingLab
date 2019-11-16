#pragma once
#include <iostream>
#include <vector>

class NodeDynamic {

private:
	std::vector<NodeDynamic *> children;
	NodeDynamic *parentNode;
	int val;
	void deleteAllNodes(NodeDynamic * currentNode);

public:
	NodeDynamic() { val = 0; parentNode = NULL; };
	NodeDynamic(NodeDynamic * parent) { val = 0; parentNode = parent; };
	~NodeDynamic();

	void setValue(int newVal) { val = newVal; };

	int getChildrenNumber() { return(children.size()); };
	void addNewChild();
	void addNewChild(NodeDynamic * newChild);
	NodeDynamic *getChild(int childOffset);
	NodeDynamic *getParent() { return parentNode; };
	void setParent(NodeDynamic * newParent) { parentNode = newParent; };
	bool deleteChild(NodeDynamic * childNode);

	void print() { std::cout << " " << val; };
	void printAllBelow();
	void printUp();

	

};