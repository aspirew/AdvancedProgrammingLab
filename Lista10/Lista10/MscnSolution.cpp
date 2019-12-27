#include "MscnSolution.h"

MscnSolution::MscnSolution(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm) {
	this->xd = xd;
	this->xf = xf;
	this->xm = xm;
}

MscnSolution::MscnSolution(MscnSolution const & sol){
	this->xd = new Matrix<double>(*(sol.xd));
	this->xf = new Matrix<double>(*(sol.xf));
	this->xm = new Matrix<double>(*(sol.xm));
}

MscnSolution::~MscnSolution() {
	delete xd;
	delete xf;
	delete xm;
}

double * MscnSolution::toDouble() {

	double * res = new double[xd->getFullSize() + xf->getFullSize() + xm->getFullSize()];
	int xdSize = xd->getWidth()*xd->getHeigth();
	int xfSize = xf->getWidth()*xf->getHeigth();
	int xmSize = xm->getWidth()*xm->getHeigth();

	double * xdd = xd->toDouble();
	double * xff = xf->toDouble();
	double * xmm = xm->toDouble();

	std::copy(xdd, xdd + xdSize, res);
	std::copy(xff, xff + xfSize, res + xdSize);
	std::copy(xmm, xmm + xmSize, res + xdSize + xfSize);

	delete xdd;
	delete xff;
	delete xmm;

	return res;
}

void MscnSolution::operator=(const MscnSolution & sol){
	this->xd = new Matrix<double>(*(sol.xd));
	this->xf = new Matrix<double>(*(sol.xf));
	this->xm = new Matrix<double>(*(sol.xm));
}

std::ostream& operator<<(std::ostream &os, const MscnSolution &sol) {
	//os << "xd" << *(sol.xd) << "\n";
	//os << "xf" << *(sol.xf) << "\n";
	//os << "xm" << *(sol.xm) << "\n";

	os << "xd \n";
	for (int i = 0; i < sol.xd->getHeigth(); i++) {
		for (int j = 0; j < sol.xd->getWidth(); j++) {
			os << sol.xd->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "xf \n";
	for (int i = 0; i < sol.xf->getHeigth(); i++) {
		for (int j = 0; j < sol.xf->getWidth(); j++) {
			os << sol.xf->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "xm \n";
	for (int i = 0; i < sol.xm->getHeigth(); i++) {
		for (int j = 0; j < sol.xm->getWidth(); j++) {
			os << sol.xm->getElem(i, j) << " ";
		}
		os << "\n";
	}

	return os;
}


