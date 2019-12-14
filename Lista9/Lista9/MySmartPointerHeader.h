#pragma once
#include "RefCounterHeader.h"

template <typename T>
class MySmartPointer{
public:

	MySmartPointer(T *pcPointer, bool isArray);

	MySmartPointer(const MySmartPointer &pcOther);

	~MySmartPointer();

	T& operator*() { return(*pointer); }
	T* operator->() { return(pointer); }
	T& operator[](int i) { if (isArray) return pointer[i]; }

	MySmartPointer duplicate();

	MySmartPointer operator=(const MySmartPointer & otherSmartPointer);

private:
	RefCounter *counter;
	T *pointer;
	bool isArray;
	void destroy();
};