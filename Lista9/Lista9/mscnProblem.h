#pragma once
#include <vector>
#include "Matrix.cpp"

class MscnSolution {

public:
	Matrix<double> *xd, *xf, *xm;

	MscnSolution(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm) {
		this->xd = xd;
		this->xf = xf;
		this->xm = xm;
	}

	~MscnSolution() {
		std::cout << "DESTROY MSCNSOL";
		delete xd;
		delete xf;
		delete xm;
	}

};

struct MinMaxValues {
	int min;
	int max;
};


class MscnProblem {
public:

	MscnProblem();
	~MscnProblem() { std::cout << "problem out"; }

	bool setCountOfD(int val);
	bool setCountOfF(int val);
	bool setCountOfM(int val);
	bool setCountOfS(int val);

	bool setInCd(double val, int y, int x);
	bool setInCf(double val, int y, int x);
	bool setInCm(double val, int y, int x);

	double getFromCd(int y, int x);
	double getFromCf(int y, int x);
	double getFromCm(int y, int x);

	bool setInUd(double val, int x);
	bool setInUf(double val, int x);
	bool setInUm(double val, int x);
	bool setInSd(double val, int x);
	bool setInSf(double val, int x);
	bool setInSm(double val, int x);
	bool setInSs(double val, int x);
	bool setInPs(double val, int x);

	double getFromUd(int x);
	double getFromUf(int x);
	double getFromUm(int x);
	double getFromSd(int x);
	double getFromSf(int x);
	double getFromSm(int x);
	double getFromSs(int x);
	double getFromPs(int x);

	double getQuality(double *solution, int arrSize);
	double constraintsSatisfied(double *solution, int arrSize);

	int getSolutionErrorState() { return solutionErrorState; }

	std::vector<MinMaxValues> getMinMaxValues();

	void printAll();


private:

	int d, f, m, s;

	bool setInVectorOfDoubles(double val, int x, std::vector<double> &vector);
	double getFromVectorOfDoubles(int x, std::vector<double> &vector);

	bool setInVectorOfInts(int val, int x, std::vector<int> &vector);
	double getFromVectorOfInts(int x, std::vector<int> &vector);

	double getKT(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm);
	double getKU(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm);
	double getP(Matrix<double> *xm);

	MscnSolution getSolution(double *solution);
	double getProfit(MscnSolution sol);
	int checkIfSolutionIsValid(double *solution, int arrSize);

	bool constraintsCheck(MscnSolution &sol);

	int eps(double x);

	Matrix<double> * cd, * cf, * cm;
	std::vector<double> ud, uf, um, sd, sf, sm, ss, ps;
	std::vector<int> minxd, maxxd, minxf, maxxf, minxm, maxxm;

	int solutionErrorState = 0;
};