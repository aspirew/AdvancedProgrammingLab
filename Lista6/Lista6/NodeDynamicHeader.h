#pragma once
#include "CONST_H.h"

template <typename T>
class NodeDynamic {

private:
	std::vector<NodeDynamic *> children;
	NodeDynamic *parentNode;
	T val;
	void setDefaultKnownType();

public:
	NodeDynamic();
	NodeDynamic(NodeDynamic * parent);
	~NodeDynamic();

	void setValue(T newVal) { val = newVal; };
	T getValue() { return val; };

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

	NodeDynamic * getRoot();

	int checkNumberOfLeaves();

};