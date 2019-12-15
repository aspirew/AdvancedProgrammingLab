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

std::ostream& operator<<(std::ostream &os, const MscnSolution &sol) {
	//os << "xd" << *(sol.xd) << "\n";
	//os << "xf" << *(sol.xf) << "\n";
	//os << "xm" << *(sol.xm) << "\n";

	os << "xd\n";
	for (int i = 0; i < sol.xd->getHeigth(); i++) {
		for (int j = 0; j < sol.xd->getWidth(); j++) {
			os << sol.xd->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "xf\n";
	for (int i = 0; i < sol.xf->getHeigth(); i++) {
		for (int j = 0; j < sol.xf->getWidth(); j++) {
			os << sol.xf->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "xm\n";
	for (int i = 0; i < sol.xm->getHeigth(); i++) {
		for (int j = 0; j < sol.xm->getWidth(); j++) {
			os << sol.xm->getElem(i, j) << " ";
		}
		os << "\n";
	}

	return os;
}

std::ostream & saveData(std::ostream & os, const MscnSolution &sol){
	os << "xd\n";
	for (int i = 0; i < sol.xd->getHeigth(); i++) {
		for (int j = 0; j < sol.xd->getWidth(); j++) {
			os << sol.xd->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "xf\n";
	for (int i = 0; i < sol.xf->getHeigth(); i++) {
		for (int j = 0; j < sol.xf->getWidth(); j++) {
			os << sol.xf->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "xm\n";
	for (int i = 0; i < sol.xm->getHeigth(); i++) {
		for (int j = 0; j < sol.xm->getWidth(); j++) {
			os << sol.xm->getElem(i, j) << " ";
		}
		os << "\n";
	}

	return os;
}
