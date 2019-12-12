#include "MySmartPointerHeader.h"

template <typename T>
MySmartPointer<T>::MySmartPointer(T *pcPointer) {
	pointer = pcPointer;
	counter = new RefCounter();
	counter->add();
}

template <typename T>
MySmartPointer<T>::MySmartPointer(const MySmartPointer &pcOther) {
	pointer = pcOther.pointer;
	counter = pcOther.counter;
	counter->add();
}

template <typename T>
MySmartPointer<T>::~MySmartPointer(){
	if (counter->dec() == 0)
	{
		delete pointer;
		delete counter;
	}
}

template <typename T>
MySmartPointer<T> MySmartPointer<T>::operator=(const MySmartPointer & otherSmartPointer) {

	if (&otherSmartPointer == this) return *this;

	if (counter->dec() == 0) {
		delete pointer;
		delete counter;
	}

	pointer = otherSmartPointer.pointer;
	counter = otherSmartPointer.counter;
	counter->add();

	return *this;
}

template <typename T>
MySmartPointer<T> MySmartPointer<T>::duplicate() {
	return MySmartPointer(new T(*this->pointer));
}
