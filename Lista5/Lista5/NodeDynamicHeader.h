#pragma once
#include <iostream>
#include <vector>

class NodeDynamic {

private:
	std::vector<NodeDynamic *> children;
	NodeDynamic *parentNode;
	int val;

public:
	NodeDynamic();
	NodeDynamic(NodeDynamic * parent);
	~NodeDynamic();

	void setValue(int newVal) { val = newVal; };
	int getValue() { return val; };

	int getChildrenNumber() { return(children.size()); };
	void addNewChild();
	void addNewChild(NodeDynamic * newChild);
	NodeDynamic *getChild(int childOffset);
	NodeDynamic *getParent() { return parentNode; };
	void setParent(NodeDynamic * newParent) { parentNode = newParent; };
	bool deleteChild(NodeDynamic * childNode);

	void print();
	void extraPrint();
	void printAllBelow();
	void printUp();

	

};