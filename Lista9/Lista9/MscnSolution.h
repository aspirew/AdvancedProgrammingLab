#pragma once
#include "matrix.cpp"

struct MsncSolution {
	Matrix<double> * xd;
	Matrix<double> * xf;
	Matrix<double> * xm;

	~MsncSolution() {
		delete xd;
		delete xf;
		delete xm;
	}

};

struct MinMaxValues {
	double min;
	double max;
};

class MscnSolution {
public:

	MscnSolution() {}
	MscnSolution(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm);
	~MscnSolution();

	Matrix<double> * getXd() { return *xd; }
	Matrix<double> * getXf() { return *xf; }
	Matrix<double> * getXm() { return *xm; }

private:

	Matrix<double> * xd;
	Matrix<double> * xf;
	Matrix<double> * xm;
};