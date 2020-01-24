#pragma once
#include "CONST_H.h"

template <typename T>
class MscnSolution {

public:

  Matrix<T> *xd, *xf, *xm;

	MscnSolution();

	MscnSolution(Matrix<T> *xd, Matrix<T> *xf, Matrix<T> *xm);

	MscnSolution(MscnSolution<T> const &sol);

	~MscnSolution();


	T * toTypeTable();

	friend std::ostream& operator<<(std::ostream &os, const MscnSolution<T> &p);

	void operator=(const MscnSolution<T> &sol);
	bool operator==(const MscnSolution<T> &sol);


};
