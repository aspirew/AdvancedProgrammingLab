#include "MscnSolution.h"

MscnSolution::MscnSolution(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm) {
	this->xd = xd;
	this->xf = xf;
	this->xm = xm;
}

MscnSolution::~MscnSolution() {
	delete xd;
	delete xf;
	delete xm;
}

