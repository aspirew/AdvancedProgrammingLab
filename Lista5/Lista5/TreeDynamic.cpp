#include "TreeDynamicHeader.h"

void TreeDynamic::printTree() {
	root->printAllBelow();
}

bool TreeDynamic::moveSubtree(NodeDynamic * parentNode, NodeDynamic * newChildNode) {

	if (parentNode == NULL || newChildNode == NULL) return false;

	if (doBelongToSameTree(parentNode, newChildNode)) return false;

	if (newChildNode->getParent() == NULL) return false;

	if (newChildNode->getParent()->deleteChild(newChildNode) == false) return false;

	parentNode->addNewChild(newChildNode);

	return true;
}

bool TreeDynamic::doBelongToSameTree(NodeDynamic * node1, NodeDynamic * node2) {
	return node1->getRoot() == node2->getRoot();
}