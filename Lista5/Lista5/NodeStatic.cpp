#include "NodeStaticHeader.h"

NodeStatic::~NodeStatic() {
	//std::cout << "deleting node with val: " << val << " and address: " << this << std::endl;
}

NodeStatic & NodeStatic::operator=(NodeStatic const &node) {

	if (this == &node) return *this;

	val = node.val;
	parentNode = node.parentNode;

	for (int i = 0; i < node.children.size(); i++) {
		this->children.push_back(node.children.at(i));
	}

	return *this;
}

//bool NodeStatic::operator!=(NodeStatic &pcOther) {
//	return !operator==(pcOther);
//}
//
//bool NodeStatic::operator==(NodeStatic &other) {
//	if (val != other.val) {
//		return false;
//	}
//	if (children.size() != other.children.size()) {
//		return false;
//	}
//	for (int i = 0; i < getChildrenNumber(); i++) {
//		if (children[i] != other.children[i]) {
//			return false;
//		}
//	}
//	return true;
//}

void NodeStatic::addNewChild() {
	children.push_back(NodeStatic(this));
}

void NodeStatic::addNewChild(NodeStatic & newChild) {

	NodeStatic nodeToAdd;
	nodeToAdd = newChild;

	children.push_back(nodeToAdd);
	adoptChildren();
}

NodeStatic * NodeStatic::getChild(int childOffset) {
	if (childOffset < 0 || childOffset > getChildrenNumber() - 1) return NULL;
	return &children.at(childOffset);
}

void NodeStatic::adoptChildren() {
	for (int i = 0; i < getChildrenNumber(); i++) {
		children.at(i).setParent(this);
	}
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