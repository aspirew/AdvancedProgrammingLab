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

	friend std::ostream& operator<<(std::ostream &os, const MscnSolution<T> &sol) {
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

	void operator=(const MscnSolution<T> &sol);
	bool operator==(const MscnSolution<T> &sol);


};
