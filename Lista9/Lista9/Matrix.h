#pragma once
#include <vector>

template <typename T>
class Matrix {

public:

	Matrix();
	Matrix(int heigth, int width);

	bool resize(int heigth, int width);

	T getElem(int y, int x);
	bool setElem(double val, int y, int x);

	void print();


//private:

	int heigth;
	int width;
	int fullSize;

	double * allElements; //DESTRUKTOR

	bool initializeMatrix(int heigth, int width);

	bool correctSize(int y, int x);
};