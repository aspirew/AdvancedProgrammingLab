#pragma once
#include "Matrix.cpp"
#include "MscnSolution.cpp"
#include "vectorHelper.cpp"
#include "MinMaxValues.h"
#include "CONST_H.h"

class MscnProblem {
public:

	MscnProblem();
	MscnProblem(std::string fileName);
	~MscnProblem();

	bool setCountOfD(int val);
	bool setCountOfF(int val);
	bool setCountOfM(int val);
	bool setCountOfS(int val);

	bool setInCd(double val, int y, int x) { return cd->setElem(val, y, x); }
	bool setInCf(double val, int y, int x) { return cf->setElem(val, y, x); }
	bool setInCm(double val, int y, int x) { return cm->setElem(val, y, x); }

	double getFromCd(int y, int x) { return cd->getElem(y, x); }
	double getFromCf(int y, int x) { return cf->getElem(y, x); }
	double getFromCm(int y, int x) { return cm->getElem(y, x); }


	bool setInUd(double val, int x) { return setInVectorOfDoubles(val, x, ud); }
	bool setInUf(double val, int x) { return setInVectorOfDoubles(val, x, uf); }
	bool setInUm(double val, int x) { return setInVectorOfDoubles(val, x, um); }
	bool setInSd(double val, int x) { return setInVectorOfDoubles(val, x, sd); }
	bool setInSf(double val, int x) { return setInVectorOfDoubles(val, x, sf); }
	bool setInSm(double val, int x) { return setInVectorOfDoubles(val, x, sm); }
	bool setInSs(double val, int x) { return setInVectorOfDoubles(val, x, ss); }
	bool setInPs(double val, int x) { return setInVectorOfDoubles(val, x, ps); }

	double getFromUd(int x) { return getFromVectorOfDoubles(x, ud); }
	double getFromUf(int x) { return getFromVectorOfDoubles(x, uf); }
	double getFromUm(int x) { return getFromVectorOfDoubles(x, um); }
	double getFromSd(int x) { return getFromVectorOfDoubles(x, sd); }
	double getFromSf(int x) { return getFromVectorOfDoubles(x, sf); }
	double getFromSm(int x) { return getFromVectorOfDoubles(x, sm); }
	double getFromSs(int x) { return getFromVectorOfDoubles(x, ss); }
	double getFromPs(int x) { return getFromVectorOfDoubles(x, ps); }

	double getQuality(double *solution, int arrSize);
	double constraintsSatisfied(double *solution, int arrSize);
	int getValidSize() { return d * f + f * m + m * s; }

	int getSolutionErrorState() { return solutionErrorState; }

	std::vector<MinMaxValues> getMinMaxValues(std::vector<double> &constraint);
	std::vector<MinMaxValues> getXMMinMaxValues();

	bool saveData(std::string const &path);
	bool saveSolution(double *solution, std::string const &path);

	void setRandomValues(int count);
	void setRandomElementsCount(int maxDist);

	friend std::ostream& operator<<(std::ostream &os, MscnProblem &p);

private:

	int d, f, m, s;

	void initialize();

	bool setInVectorOfDoubles(double val, int x, std::vector<double> &vector);
	double getFromVectorOfDoubles(int x, std::vector<double> &vector);

	bool setInVectorOfInts(int val, int x, std::vector<int> &vector);
	double getFromVectorOfInts(int x, std::vector<int> &vector);

	double getKT(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm);
	double getKU(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm);
	double getP(Matrix<double> *xm);

	MscnSolution getSolution(double *solution);
	MscnSolution getSolutionFromTxt(std::string fileName);
	int checkIfSolutionIsValid(double *solution, int arrSize);

	bool constraintsCheck(MscnSolution &sol);

	int eps(double x);

	Matrix<double> * cd, * cf, * cm;
	std::vector<double> ud, uf, um, sd, sf, sm, ss, ps;

	int solutionErrorState = 0;
};