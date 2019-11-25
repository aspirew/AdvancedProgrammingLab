#include "pch.h"
#include <iostream>
#include "TreeDynamic.cpp"

int main(){
    
	TreeDynamic<NodeDynamic<char>> tree1;
	TreeDynamic<NodeDynamic<int>> tree2;
	TreeDynamic<NodeDynamic<std::string>> tree3;
	TreeDynamic<NodeDynamic<double>> tree4;
	TreeDynamic<NodeDynamic<float>> tree5;
	TreeDynamic<NodeDynamic<long>> tree6;

	//std::cout << tree1.getRoot()->getValue() << std::endl;
	//std::cout << tree2.getRoot()->getValue() << std::endl;
	//std::cout << tree3.getRoot()->getValue() << std::endl;
	//std::cout << tree4.getRoot()->getValue() << std::endl;
	//std::cout << tree5.getRoot()->getValue() << std::endl;
	//std::cout << tree6.getRoot()->getValue() << std::endl;

	tree1.getRoot()->addNewChild();
	tree1.getRoot()->addNewChild();

	tree1.getRoot()->getChild(0)->addNewChild();
	tree1.getRoot()->getChild(0)->addNewChild();

	tree2.getRoot()->addNewChild();
	tree2.getRoot()->addNewChild();

	tree2.getRoot()->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->addNewChild();
	tree2.getRoot()->getChild(1)->addNewChild();

	tree3.getRoot()->addNewChild();
	tree3.getRoot()->getChild(0)->addNewChild();
	tree3.getRoot()->getChild(0)->getChild(0)->addNewChild();


	std::cout << tree1.getNumberOfLeaves() << std::endl;
	std::cout << tree2.getNumberOfLeaves() << std::endl;
	std::cout << tree3.getNumberOfLeaves() << std::endl;

	tree3.printTree();

}
