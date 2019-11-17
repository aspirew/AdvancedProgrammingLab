#include "TreeDynamicHeader.h"

void TreeDynamic::printTree() {
	root->printAllBelow();
}

bool TreeDynamic::moveSubtree(NodeDynamic * parentNode, NodeDynamic * newChildNode) {

	if (parentNode == NULL || newChildNode == NULL) return false;

	if (newChildNode->getParent()->deleteChild(newChildNode) == false) return false;

	parentNode->addNewChild(newChildNode);

	return true;
}
