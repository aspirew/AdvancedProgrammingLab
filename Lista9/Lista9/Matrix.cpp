#include "Matrix.h"
#include <iostream>
#include "MinMaxValues.h"

template <typename T>
Matrix<T>::Matrix() { }

template <typename T>
Matrix<T>::Matrix(int heigth, int width, std::istream &is) {
	initializeMatrix(heigth, width);

	for (int i = 0; i < heigth; i++)
		for (int j = 0; j < width; j++) {
			T result;
			is >> result;
			setElem(result, i, j);
		}
}

Matrix<MinMaxValues>::Matrix(int heigth, int width, std::istream &is) {
	initializeMatrix(heigth, width);

	double min = 0;
	double max = 0;

	for (int i = 0; i < heigth; i++)
		for (int j = 0; j < width; j++) {
			is >> min;
			is >> max;
			setElem({ min, max }, i, j);
		}
}

template <typename T>
Matrix<T>::Matrix(int heigth, int width) {
	initializeMatrix(heigth, width);
}

template <typename T>
Matrix<T>::~Matrix() {

	for (int i = 0; i < heigth; i++) {
		delete[] allElements[i];
	}
	delete[] allElements;
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

	allElements = new T*[heigth]();
	for (int i = 0; i < heigth; i++) {
		allElements[i] = new T[width]();
	}

	return true;
}

template <typename T>
bool Matrix<T>::resize(int heigth, int width) {

	if (heigth <= 0 || width <= 0) return false;

	if (heigth == this->heigth && width == this->width) return true;

	T ** tmp = new T*[heigth]();
	for (int i = 0; i < heigth; i++) {
		tmp[i] = new T[width]();
	}

	int smallerHeigth = (heigth < this->heigth) ? heigth : this->heigth;
	int smallerWidth = (width < this->width) ? width : this->width;

		for (int i = 0; i < smallerHeigth; i++) {
			for (int j = 0; j < smallerWidth; j++) {
				tmp[i][j] = allElements[i][j];
			}
		}

	for (int i = 0; i < this->heigth; i++) {
		delete[] allElements[i];
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
		return allElements[y][x];
}

template <typename T>
bool Matrix<T>::setElem(T val, int y, int x) {
	if (!correctSize(y, x)) return false;

	allElements[y][x] = val;

	return true;
}

template <typename T>
T Matrix<T>::sumOneRow(int row) {
	T result = NULL;
	for (int i = 0; i < width; i++) {
		result += allElements[row][i];
	}

	return result;
}

template <typename T>
T Matrix<T>::sumOneCol(int col) {
	T result = NULL;
	for (int i = 0; i < heigth; i++) {
		result += allElements[i][col];
	}

	return result;
}

template <typename T>
T Matrix<T>::sumWholeMat() {
	T result;
	for (int i = 0; i < heigth; i++) {
		result += sumOneRow(i);
	}

	return result;
}

template <typename T>
double * Matrix<T>::toDouble() {
	double * res = new double[heigth*width];
	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			res[i*width+j] = getElem(i, j);
		}
	}
	return res;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const Matrix<T> &mat) {
	
	os << mat.width << " " << mat.heigth << "\n";
	for (int i = 0; i < mat.heigth; i++) {
		for (int j = 0; j < mat.width; j++) {
			os << mat.getElem(i, j);
		}
		os << "\n";
	}
	return os;
}

