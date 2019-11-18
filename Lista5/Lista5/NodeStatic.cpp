#include "NodeStaticHeader.h"

NodeStatic::NodeStatic() {
	val = 0; parentNode = NULL;
}

NodeStatic::NodeStatic(NodeStatic * parent) {
	val = 0; 
	parentNode = parent;
}

//NodeStatic::NodeStatic(const NodeStatic & other) {
//	parentNode = other.parentNode;
//	children = other.children;
//	val = other.val;
//	setParentToAllChildrenAndGrandchildren();
//}

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

	setParentToAllChildrenAndGrandchildren();

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
//		if (children.at(i) != other.children.at(i)) {
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
	children.at(getChildrenNumber() - 1).setParentToAllChildrenAndGrandchildren();
	
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

void NodeStatic::setParentToAllChildrenAndGrandchildren() {
	for (int i = 0; i < getChildrenNumber(); i++) {
		children.at(i).setParent(this);
		children.at(i).setParentToAllChildrenAndGrandchildren();
	}
}

void NodeStatic::print() {
	std::cout << " " << val;
}

void NodeStatic::extraPrint(){
	std::cout << VALUE_CAPTION;
	print();
	std::cout << ADDRESS_CAPTION << this << PARENT_VALUE_CAPTION << ((parentNode != NULL) ? parentNode->getValue() : NULL) << PARENT_ADDRESS_CAPTION << parentNode << std::endl;
}

void NodeStatic::printAllBelow() {
	print();
	if (getChildrenNumber() > 0) {
		std::cout << " ( ";
		for (int i = 0; i < getChildrenNumber(); i++) {
			children.at(i).printAllBelow();
		}
		std::cout << " ) ";
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
			children.at(i).deleteAllChildren();
			children.erase(children.begin() + i);
			return true;
		}
	}
	return false;
}

void NodeStatic::deleteAllChildren() {
	for (int i = 0; i < getChildrenNumber(); i++) {
		children.at(i).deleteAllChildren();
		children.clear();
	}
}

NodeStatic * NodeStatic::getRoot() {
	if (parentNode != NULL) {
		return parentNode->getRoot();
	}
	else return this;
}