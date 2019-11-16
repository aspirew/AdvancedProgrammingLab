#include "TreeStaticHeader.h"

void TreeStatic::printTree() {
	root.printAllBelow();
}

bool TreeStatic::moveSubtree(NodeStatic * parentNode, NodeStatic * newChildNode) {

	if (parentNode == NULL || newChildNode == NULL) return false;

	if (newChildNode->getParent()->deleteChild(newChildNode) == false) return false;

	std::cout << newChildNode->getValue() << "SDAFASGA" << std::endl;

	parentNode->addNewChild(*newChildNode);

	return true;
}