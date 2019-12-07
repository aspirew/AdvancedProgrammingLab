#include "Tab.h"

Tab::Tab(const Tab &other){

	copy(other);
	std::cout << "Copy ";
}

Tab::Tab(Tab &&other){

	tab = other.tab;
	size = other.size;
	other.tab = NULL;

	std::cout << "MOVE ";
}

Tab& Tab::operator=(const Tab &other){

	if (tab != NULL) delete[] tab;
	copy(other);

	std::cout << "op= ";
	return *this;
}

Tab& Tab::operator=(Tab &&other) {

	if (tab != NULL) delete[] tab;
	
	tab = other.tab;
	size = other.size;
	other.tab = NULL;

	std::cout << "op= &&";
	return *this;
}

Tab::~Tab(){
	if (tab != NULL) delete[] tab;
	std::cout << "Destr ";
}

bool Tab::setSize(int newSize){

	if (newSize < 1) return false;
	if (newSize == size) return true;
	int *newTable = new int[newSize];
	int copyLen = (newSize < size) ? newSize : size;

	for (int i = 0; i < copyLen; i++){
		newTable[i] = tab[i];
	}

	delete[] tab;
	tab = newTable;
	size = newSize;
	return true;

}

void Tab::copy(const Tab &other){

	tab = new int[other.size];
	size = other.size;

	for (int i = 0; i < other.size; i++)
		tab[i] = other.tab[i];

}