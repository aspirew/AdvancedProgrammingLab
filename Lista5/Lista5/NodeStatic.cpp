#include "NodeStaticHeader.h"
#include "NodeStaticHeader.h"

NodeStatic::~NodeStatic() {
	std::cout << "deleting node with val: " << val << " and address: " << this << std::endl;
}

void NodeStatic::addNewChild() {
	children.push_back(NodeStatic(this));
}

void NodeStatic::addNewChild(NodeStatic * newChild) {
	NodeStatic newNode = newChild;
	newNode.setParent(this);
	children.push_back(newNode);
}

NodeStatic * NodeStatic::getChild(int childOffset) {

	if (childOffset < 0 || childOffset > getChildrenNumber() - 1) return NULL;

	return &children.at(childOffset);
}

void NodeStatic::printAllBelow() {
	print();
	for (int i = 0; i < getChildrenNumber(); i++) {
		children.at(i).printAllBelow();
	}
}

void NodeStatic::printUp() {
	print();
	if (parentNode != NULL) {
		parentNode->printUp();
	}
}

bool NodeStatic::deleteChild(NodeStatic * child) {
	for (int i = 0; i < getChildrenNumber(); i++) {
		if (&children.at(i) == child) {
			children.erase(children.begin() + i);
			return true;
		}
	}
	return false;
}
//
//NodeStatic & NodeStatic::operator=(NodeStatic &node) {
//
//	if (this == &node) return *this;
//
//	val = node.val;
//
//
//	return *this;
//}