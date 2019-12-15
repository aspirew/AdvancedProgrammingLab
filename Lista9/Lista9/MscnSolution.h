#pragma once
#include "CONST_H.h"

class MscnSolution {

public:

	Matrix<double> *xd, *xf, *xm;

	MscnSolution() {};

	MscnSolution(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm);

	~MscnSolution();

	friend std::ostream& operator<<(std::ostream &os, const MscnSolution &p);

};