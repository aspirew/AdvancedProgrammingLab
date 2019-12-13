#include "Matrix.h"
#include <iostream>

template <typename T>
Matrix<T>::Matrix() {

}

template <typename T>
Matrix<T>::Matrix(int heigth, int width) {
	initializeMatrix(heigth, width);
}

template <typename T>
bool Matrix<T>::correctSize(int y, int x) {
	return (y >= 0 && y < heigth && x >= 0 && x < width);
}

template <typename T>
bool Matrix<T>::initializeMatrix(int heigth, int width) {
	if (heigth < 1 || width < 1) return false;

	this->width = width;
	this->heigth = heigth;
	this->fullSize = heigth * width;

	allElements = new double[fullSize]();

	return true;
}

template <typename T>
bool Matrix<T>::resize(int heigth, int width) {

	if (heigth <= 0 || width <= 0) return false;

	if (heigth == this->heigth && width == this->width) return true;

	double * tmp = new double[heigth * width]();

	int smallerHeigth = (heigth < this->heigth) ? heigth : this->heigth;
	int smallerWidth = (width < this->width) ? width : this->width;
	int sizeOfOffset = this->width - width;
	int offset = 0;

	//TODO: get rid off redundant instructions

	if (sizeOfOffset >= 0) {
		for (int i = 0; i < smallerHeigth; i++) {
			for (int j = 0; j < smallerWidth; j++) {
				tmp[i * smallerWidth + j] = allElements[i * smallerWidth + j + offset];
			}
			offset += sizeOfOffset;
		}
	}

	if (sizeOfOffset < 0) {
		for (int i = 0; i < smallerHeigth; i++) {
			for (int j = 0; j < smallerWidth; j++) {
				tmp[i * smallerWidth + j - offset] = allElements[i * smallerWidth + j];
			}
			offset += sizeOfOffset;
		}
	}

	delete[] allElements;

	allElements = tmp;

	this->width = width;
	this->heigth = heigth;
	this->fullSize = heigth * width;

	return true;

}

template <typename T>
T Matrix<T>::getElem(int y, int x) {
	if(correctSize(y, x)) 
		return allElements[y * width + x];
}

template <typename T>
bool Matrix<T>::setElem(double val, int y, int x) {
	if (!correctSize(y, x)) return false;
	
	allElements[y * width + x] = val;

	return true;
}

template <typename T>
void Matrix<T>::print() {
	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << allElements[i * width + j] << " ";
		}
		std::cout << std::endl;
	}
}