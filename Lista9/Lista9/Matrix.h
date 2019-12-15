#pragma once
#include <vector>
#include <string>

template <typename T>
class Matrix {

public:

	Matrix();
	Matrix(std::istream &is);
	Matrix(int heigth, int width, std::string name);
	~Matrix();

	bool resize(int heigth, int width);

	T getElem(int y, int x);
	bool setElem(double val, int y, int x);

	int getFullSize() { return fullSize; }

	T sumOneRow(int row);
	T sumOneCol(int col);
	T sumWholeMat();

	friend std::ostream& operator<<(std::ostream &os, const Matrix<T> &mat);

	void print();


private:

	int heigth;
	int width;
	int fullSize;

	std::string name;

	double ** allElements;

	bool initializeMatrix(int heigth, int width);

	bool correctSize(int y, int x);
};