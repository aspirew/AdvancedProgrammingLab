#include "NodeDynamicHeader.h"

template <typename T>
NodeDynamic<T>::NodeDynamic() {
	setDefaultKnownType();
	parentNode = NULL;
}

template <typename T>
NodeDynamic<T>::NodeDynamic(NodeDynamic * parent) {
	setDefaultKnownType();
	parentNode = parent;
}

template <typename T>
NodeDynamic<T>::~NodeDynamic() {
	//std::cout << "deleting node with val: " << val << " and address: " << this << std::endl;
	for (int i = 0; i < getChildrenNumber(); i++) {
		delete children.at(i);
	}
}

template <typename T>
void NodeDynamic<T>::addNewChild() {
	children.push_back(new NodeDynamic(this));
}

template <typename T>
void NodeDynamic<T>::addNewChild(NodeDynamic * newChild) {
	newChild->setParent(this);
	children.push_back(newChild);
}

template <typename T>
NodeDynamic<T> * NodeDynamic<T>::getChild(int childOffset) {

	if (childOffset < 0 || childOffset > getChildrenNumber() - 1) return NULL;

	return children.at(childOffset);
}

template <typename T>
void NodeDynamic<T>::print() {
	std::cout << " " << val;
}

template <typename T>
void NodeDynamic<T>::extraPrint() {
	std::cout << VALUE_CAPTION;
	print();
	std::cout << ADDRESS_CAPTION << this << PARENT_VALUE_CAPTION << ((parentNode != NULL) ? parentNode->getValue() : NULL) << PARENT_ADDRESS_CAPTION << parentNode << std::endl;
}

template <typename T>
void NodeDynamic<T>::printAllBelow() {
	print();
	if (getChildrenNumber() > 0) {
		std::cout << " ( ";
		for (int i = 0; i < getChildrenNumber(); i++) {
			children.at(i)->printAllBelow();
		}
		std::cout << " ) ";
	}
}

template <typename T>
void NodeDynamic<T>::printUp() {
	extraPrint();
	if (parentNode != NULL) {
		parentNode->printUp();
	}
}

template <typename T>
bool NodeDynamic<T>::deleteChild(NodeDynamic * child) {
	for (int i = 0; i < getChildrenNumber(); i++) {
		if (children.at(i) == child) {
			children.erase(children.begin() + i);
			return true;
		}
	}
	return false;
}

template <typename T>
NodeDynamic<T> * NodeDynamic<T>::getRoot() {
	if (parentNode != NULL) {
		return parentNode->getRoot();
	}
	else return this;
}

template <typename T>
void NodeDynamic<T>::setDefaultKnownType() {
	val = NULL;
}

template <>
void NodeDynamic<int>::setDefaultKnownType() {
	val = 0;
}

template <>
void NodeDynamic<std::string>::setDefaultKnownType() {
	val = "aa";
}

template <>
void NodeDynamic<char>::setDefaultKnownType() {
	val = 'f';
}

template <>
void NodeDynamic<double>::setDefaultKnownType() {
	val = 0.5;
}

template <>
void NodeDynamic<float>::setDefaultKnownType() {
	val = 0.1f;
}

