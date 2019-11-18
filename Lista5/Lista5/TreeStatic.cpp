#include "TreeStaticHeader.h"

void TreeStatic::printTree() {
	root.printAllBelow();
}

bool TreeStatic::moveSubtree(NodeStatic * parentNode, NodeStatic * newChildNode) {

	if (parentNode == NULL || newChildNode == NULL) return false;

	if (newChildNode->getParent() == NULL) return false;

	if (doBelongToSameTree(parentNode, newChildNode)) return false;

	parentNode->addNewChild(*newChildNode);

	newChildNode->getParent()->deleteChild(newChildNode);

	return true;
}

bool TreeStatic::doBelongToSameTree(NodeStatic * node1, NodeStatic * node2) {
	return node1->getRoot() == node2->getRoot();
}