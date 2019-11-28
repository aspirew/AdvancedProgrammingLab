#pragma once
#include "RefCounterHeader.h"

template <typename T>
class MySmartPointer{
public:

	MySmartPointer(T *pcPointer);

	MySmartPointer(const MySmartPointer &pcOther);

	~MySmartPointer();

	T& operator*() { return(*pointer); }
	T* operator->() { return(pointer); }

	void operator=(const MySmartPointer & otherSmartPointer);

private:
	RefCounter *counter;
	T *pointer;
};