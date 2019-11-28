#include "pch.h"
#include "CONST_H.h"

int* createInt(int value){
	return new int(value);
}

int main(){

	MySmartPointer<int> ptr = MySmartPointer<int>(createInt(5));
	MySmartPointer<int> other = ptr;
	MySmartPointer<int> other2 = MySmartPointer<int>(createInt(2));

	std::cout << *ptr << *other << *other2 <<std::endl;

	other = other2;
	other2 = ptr;
	other = ptr;

	std::cout << *ptr << *other << *other2;

	return 0;
    
}