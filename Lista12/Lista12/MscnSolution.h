#pragma once
#include "CONST_H.h"

class MscnSolution {

public:

  Matrix<double> *xd, *xf, *xm;

	MscnSolution();

	MscnSolution(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm);

	MscnSolution(MscnSolution const &sol);

	~MscnSolution();

	double * toDouble();

	friend std::ostream& operator<<(std::ostream &os, const MscnSolution &p);

	void operator=(const MscnSolution &sol);
	bool operator==(const MscnSolution &sol);


};
