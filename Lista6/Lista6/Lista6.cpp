#include "pch.h"
#include <iostream>
#include "TreeDynamic.cpp"

int main(){
    
	TreeDynamic<NodeDynamic<char>> tree;

	std::cout << tree.getRoot()->getValue();

}
