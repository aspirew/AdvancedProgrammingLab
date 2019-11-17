#include "NodeDynamicHeader.h"

NodeDynamic::NodeDynamic() {
	val = 0; 
	parentNode = NULL;
}

NodeDynamic::NodeDynamic(NodeDynamic * parent) {
	val = 0; 
	parentNode = parent;
}

NodeDynamic::~NodeDynamic() {
	//std::cout << "deleting node with val: " << val << " and address: " << this << std::endl;
	for (int i = 0; i < getChildrenNumber(); i++) {
		delete children.at(i);
	}
}

void NodeDynamic::addNewChild() {
	children.push_back(new NodeDynamic(this));
}

void NodeDynamic::addNewChild(NodeDynamic * newChild) {
	newChild->setParent(this);
	children.push_back(newChild);
}

NodeDynamic * NodeDynamic::getChild(int childOffset) {

	if (childOffset < 0 || childOffset > getChildrenNumber() - 1) return NULL;

	return children.at(childOffset);
}

void NodeDynamic::print() {
	std::cout << " " << val;
}

void NodeDynamic::extraPrint() {
	std::cout << VALUE_CAPTION;
	print();
	std::cout << ADDRESS_CAPTION << this << PARENT_VALUE_CAPTION << ((parentNode != NULL) ? parentNode->getValue() : NULL) << PARENT_ADDRESS_CAPTION << parentNode << std::endl;
}

void NodeDynamic::printAllBelow() {
	extraPrint();
	for (int i = 0; i < getChildrenNumber(); i++) {
		children.at(i)->printAllBelow();
	}
}

void NodeDynamic::printUp() {
	extraPrint();
	if (parentNode != NULL) {
		parentNode->printUp();
	}
}

bool NodeDynamic::deleteChild(NodeDynamic * child) {
	for (int i = 0; i < getChildrenNumber(); i++) {
		if (children.at(i) == child) {
			children.erase(children.begin() + i);
			return true;
		}
	}
	return false;
}