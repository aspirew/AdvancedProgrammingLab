#pragma once
#include <vector>

template <typename T>
class Matrix<T> {

public:

	Matrix();
	Matrix(width, height);


private:

	int height;
	int width;

	std::vector<T> allElements;
};