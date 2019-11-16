#include "pch.h"
#include <iostream>
#include "TreeStatic.cpp"
#include "TreeDynamic.cpp"

void dynamicTreeTest() {

	NodeDynamic root;

	TreeDynamic dynamicTree = TreeDynamic(&root);

	dynamicTree.getRoot()->addNewChild();
	dynamicTree.getRoot()->addNewChild();

	dynamicTree.getRoot()->getChild(0)->setValue(1);
	dynamicTree.getRoot()->getChild(1)->setValue(2);

	dynamicTree.getRoot()->getChild(0)->addNewChild();
	dynamicTree.getRoot()->getChild(0)->addNewChild();

	dynamicTree.getRoot()->getChild(0)->getChild(0)->setValue(11);
	dynamicTree.getRoot()->getChild(0)->getChild(1)->setValue(12);

	dynamicTree.getRoot()->getChild(1)->addNewChild();
	dynamicTree.getRoot()->getChild(1)->addNewChild();

	dynamicTree.getRoot()->getChild(1)->getChild(0)->setValue(21);
	dynamicTree.getRoot()->getChild(1)->getChild(1)->setValue(22);

	dynamicTree.getRoot()->getChild(0)->getChild(1)->printUp();

}

void staticTreeTest() {

	NodeStatic root;

	TreeStatic staticTree = TreeStatic(&root);

	staticTree.getRoot()->addNewChild();
	staticTree.getRoot()->addNewChild();

	staticTree.getRoot()->getChild(0)->setValue(1);
	staticTree.getRoot()->getChild(1)->setValue(2);

	staticTree.getRoot()->getChild(0)->addNewChild();
	staticTree.getRoot()->getChild(0)->addNewChild();

	staticTree.getRoot()->getChild(0)->getChild(0)->setValue(11);
	staticTree.getRoot()->getChild(0)->getChild(1)->setValue(12);

	staticTree.getRoot()->getChild(1)->addNewChild();
	staticTree.getRoot()->getChild(1)->addNewChild();

	staticTree.getRoot()->getChild(1)->getChild(0)->setValue(21);
	staticTree.getRoot()->getChild(1)->getChild(1)->setValue(22);

	//staticTree.getRoot()->getChild(0)->getChild(1)->printUp();

	staticTree.printTree();

}

void movingSubtreeTest() {

	NodeDynamic root1;
	NodeDynamic root2;

	TreeDynamic tree1 = TreeDynamic(&root1);
	TreeDynamic tree2 = TreeDynamic(&root2);

	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();

	tree1.getRoot()->getChild(0)->setValue(10);
	tree1.getRoot()->getChild(1)->setValue(11);

	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();

	tree2.getRoot()->getChild(0)->setValue(20);
	tree2.getRoot()->getChild(1)->setValue(21);

	tree1.moveSubtree(tree2.getRoot()->getChild(1), tree1.getRoot()->getChild(0));

	tree2.printTree();
	std::cout << std::endl;
	tree1.printTree();
	std::cout << std::endl;

}

int main(){
	staticTreeTest();
}