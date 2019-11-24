#include "TreeDynamicHeader.h"

template <typename T>
void TreeDynamic<T>::printTree() {
	root->printAllBelow();
}

template <typename T>
bool TreeDynamic<T>::moveSubtree(T * parentNode, T * newChildNode) {

	if (parentNode == NULL || newChildNode == NULL) return false;

	if (doBelongToSameTree(parentNode, newChildNode)) return false;

	if (newChildNode->getParent() == NULL) return false;

	if (newChildNode->getParent()->deleteChild(newChildNode) == false) return false;

	parentNode->addNewChild(newChildNode);

	return true;
}

template <typename T>
bool TreeDynamic<T>::doBelongToSameTree(T * node1, T * node2) {
	return node1->getRoot() == node2->getRoot();
}

template <typename T>
std::string TreeDynamic<T>::getKnownType() {
	std::string type = TEMPLATE_TYPES.UNKNOWN;
	return type;
}

//template <typename T>
//std::string TreeDynamic<NodeDynamic<T>>::getKnownType() {
//	return TEMPLATE_TYPES.NODE_DYNAMIC;
//}

//template <typename T>
//std::string TreeDynamic<NodeStatic<T>>::getKnownType() {
//	return TEMPLATE_TYPES.NODE_DYNAMIC;
//}