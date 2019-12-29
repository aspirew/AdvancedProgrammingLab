#pragma once
#include <vector>
#include <string>

template <typename T>
class Matrix {

public:

	Matrix();
	Matrix(int heigth, int width, std::istream &is);
	Matrix(int heigth, int width);
	Matrix(Matrix<T> &mat);
	~Matrix();

	bool resize(int heigth, int width);

	T getElem(int y, int x);
  T getElemByOneDimIndex(int index);
	bool setElem(T val, int y, int x);

	int getWidth() { return width; }
	int getHeigth() { return heigth; }
	int getFullSize() { return fullSize; }

	T sumOneRow(int row);
	T sumOneCol(int col);
	T sumWholeMat();

	double * toDouble();

	void operator=(const Matrix<T> &mat);

	friend std::ostream& operator<<(std::ostream &os, const Matrix<T> &mat);

private:

	int heigth;
	int width;
	int fullSize;

	T ** allElements;

	bool initializeMatrix(int heigth, int width);

	bool correctSize(int y, int x);
};
