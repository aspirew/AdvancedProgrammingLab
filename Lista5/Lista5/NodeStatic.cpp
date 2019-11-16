#include "NodeStaticHeader.h"

NodeStatic::~NodeStatic() {
	std::cout << "deleting node with val: " << val << " and address: " << this << std::endl;
}

void NodeStatic::addNewChild() {
	children.push_back(NodeStatic(this));
}

void NodeStatic::addNewChild(NodeStatic & newChild) {

	NodeStatic nodeToAdd;
	nodeToAdd = newChild;

	children.push_back(nodeToAdd);
	printAllBelow();
	std::cout << std::endl;
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
			children.erase(std::next(children.begin(), i));
			return true;
		}
	}
	return false;
}

NodeStatic & NodeStatic::operator=(NodeStatic &node) {

	if (this == &node) return *this;

	std::cout << "OPPPP";

	val = node.getValue();
	parentNode = node.getParent();

	for (int i = 0; i < node.getChildrenNumber(); i++) {
		this->children.push_back(node.getChild(i));
	}

	return *this;
}