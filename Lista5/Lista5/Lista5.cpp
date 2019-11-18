#include "pch.h"
#include "CONST_H.h"
#include "TreeStatic.cpp"
#include "TreeDynamic.cpp"

void dynamicTreeTest() {

	TreeDynamic dynamicTree;

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

	std::cout << std::endl;

	dynamicTree.printTree();

}

void staticTreeTest() {

	TreeStatic staticTree;

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

	staticTree.getRoot()->getChild(0)->getChild(1)->printUp();

	std::cout << std::endl;

	staticTree.printTree();

}

void movingDynamicSubtreeTest() {

	TreeDynamic tree1;
	TreeDynamic tree2;

	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();

	tree1.getRoot()->getChild(0)->setValue(10);
	tree1.getRoot()->getChild(1)->setValue(11);

	tree1.getRoot()->getChild(0)->addNewChild();
	tree1.getRoot()->getChild(0)->addNewChild();

	tree1.getRoot()->getChild(0)->getChild(0)->setValue(100);
	tree1.getRoot()->getChild(0)->getChild(1)->setValue(101);

	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();

	tree2.getRoot()->getChild(0)->setValue(20);
	tree2.getRoot()->getChild(1)->setValue(21);

	tree2.printTree();
	std::cout << std::endl;
	tree1.printTree();
	std::cout << std::endl;

	tree1.moveSubtree(tree2.getRoot()->getChild(0), tree1.getRoot()->getChild(0));

	tree2.printTree();
	std::cout << std::endl;
	tree1.printTree();
	std::cout << std::endl;

	tree2.getRoot()->getChild(0)->getChild(0)->getChild(0)->printUp();

}

void movingStaticSubtreeTest() {

	TreeStatic tree1;
	TreeStatic tree2;

	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();

	tree1.getRoot()->getChild(0)->setValue(10);
	tree1.getRoot()->getChild(1)->setValue(11);

	tree1.getRoot()->getChild(0)->addNewChild();
	tree1.getRoot()->getChild(0)->addNewChild();

	tree1.getRoot()->getChild(0)->getChild(0)->setValue(100);
	tree1.getRoot()->getChild(0)->getChild(1)->setValue(101);

	tree1.getRoot()->getChild(0)->getChild(0)->addNewChild();
	tree1.getRoot()->getChild(0)->getChild(0)->addNewChild();

	tree1.getRoot()->getChild(0)->getChild(0)->getChild(0)->setValue(1000);
	tree1.getRoot()->getChild(0)->getChild(0)->getChild(1)->setValue(1001);

	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();

	tree2.getRoot()->getChild(0)->setValue(20);
	tree2.getRoot()->getChild(1)->setValue(21);

	tree2.printTree();
	std::cout << std::endl;
	tree1.printTree();
	std::cout << std::endl;

	tree1.moveSubtree(tree2.getRoot()->getChild(1), tree1.getRoot()->getChild(0));

	tree2.printTree();
	std::cout << std::endl;
	tree1.printTree();
	std::cout << std::endl;

	tree2.getRoot()->getChild(1)->getChild(0)->getChild(0)->getChild(0)->printUp();

}

void checkIfNodesBelongToSameStaticTree() {

	TreeStatic tree1;
	TreeStatic tree2;

	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();

	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();

	std::cout << tree1.doBelongToSameTree(tree1.getRoot()->getChild(0), tree2.getRoot()->getChild(1));

}

void checkIfNodesBelongToSameDynamicTree() {

	TreeDynamic tree1;
	TreeDynamic tree2;

	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();

	tree1.getRoot()->getChild(0)->addNewChild();
	tree1.getRoot()->getChild(0)->addNewChild();

	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();

	std::cout << tree1.doBelongToSameTree(tree1.getRoot()->getChild(0)->getChild(0), tree1.getRoot()->getChild(1));

}

int main() {

	std::cout << "staticTreeTest: \n\n";

	staticTreeTest();

	std::cout << "\n\ndynamicTreeTest: \n\n";

	dynamicTreeTest();

	std::cout << "\n\nmovingStaticSubtreeTest: \n\n";

	movingStaticSubtreeTest();

	std::cout << "\n\nmovingDynamicSubtreeTest: \n\n";

	movingDynamicSubtreeTest();

	std::cout << std::endl << std::endl;

	checkIfNodesBelongToSameStaticTree();
	checkIfNodesBelongToSameDynamicTree();

	
}