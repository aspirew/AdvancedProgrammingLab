#include "MscnSolution.h"

template <typename T>
MscnSolution<T>::MscnSolution() {
	this->xd = new Matrix<T>(1, 1);
	this->xf = new Matrix<T>(1, 1);
	this->xm = new Matrix<T>(1, 1);
}

template <typename T>
MscnSolution<T>::MscnSolution(Matrix<T> *xd, Matrix<T> *xf, Matrix<T> *xm) {
	this->xd = xd;
	this->xf = xf;
	this->xm = xm;
}

template <typename T>
MscnSolution<T>::MscnSolution(MscnSolution<T> const & sol){
	this->xd = new Matrix<T>(*(sol.xd));
	this->xf = new Matrix<T>(*(sol.xf));
	this->xm = new Matrix<T>(*(sol.xm));
}

template <typename T>
MscnSolution<T>::~MscnSolution() {
	delete xd;
	delete xf;
	delete xm;
}

template <typename T>
T * MscnSolution<T>::toTypeTable() {

	T * res = new T[xd->getFullSize() + xf->getFullSize() + xm->getFullSize()];
	int xdSize = xd->getWidth()*xd->getHeigth();
	int xfSize = xf->getWidth()*xf->getHeigth();
	int xmSize = xm->getWidth()*xm->getHeigth();

	T * xdd = xd->toTypeTable();
	T * xff = xf->toTypeTable();
	T * xmm = xm->toTypeTable();

	std::copy(xdd, xdd + xdSize, res);
	std::copy(xff, xff + xfSize, res + xdSize);
	std::copy(xmm, xmm + xmSize, res + xdSize + xfSize);

	delete xdd;
	delete xff;
	delete xmm;

	return res;
}

template <typename T>
void MscnSolution<T>::operator=(const MscnSolution<T> & sol){
	delete xd;
	this->xd = new Matrix<double>(*(sol.xd));
	delete xf;
	this->xf = new Matrix<double>(*(sol.xf));
	delete xm;
	this->xm = new Matrix<double>(*(sol.xm));
}

template <typename T>
bool MscnSolution<T>::operator==(const MscnSolution<T> & sol) {

  if (xd->getHeigth() != sol.xd->getHeigth() || xd->getWidth() != sol.xd->getWidth()) return false;

  for (int i = 0; i < xd->getHeigth(); i++) {
    for (int j = 0; j < xd->getWidth(); j++) {
      if (xd->getElem(i, j) != sol.xd->getElem(i, j)) return false;
    }
  }

  if (xf->getHeigth() != sol.xf->getHeigth() || xf->getWidth() != sol.xf->getWidth()) return false;

  for (int i = 0; i < xf->getHeigth(); i++) {
    for (int j = 0; j < xf->getWidth(); j++) {
      if (xf->getElem(i, j) != sol.xf->getElem(i, j)) return false;
    }
  }

  if (xm->getHeigth() != sol.xm->getHeigth() || xm->getWidth() != sol.xm->getWidth()) return false;

  for (int i = 0; i < xm->getHeigth(); i++) {
    for (int j = 0; j < xm->getWidth(); j++) {
      if (xm->getElem(i, j) != sol.xm->getElem(i, j)) return false;
    }
  }

  return true;
}

std::ostream& operator<<(std::ostream &os, const MscnSolution<double> &sol) {
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


