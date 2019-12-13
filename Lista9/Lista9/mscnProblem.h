#pragma once
#include <vector>
#include "Matrix.cpp"

struct solution {
	Matrix<double> xd, xf, xm;
};

class MscnProblem {
public:

	MscnProblem();

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

	double getQuality(double *solution);
	double constraintsSatisfied(double *solution);

	void printAll();


//private:

	int d, f, m, s;

	bool setValueIn2DimMatrix(double val, int y, int x, Matrix<double> &matrix);
	double getValueFrom2DimMatrix(int y, int x, Matrix<double> &matrix);

	bool setInVectorOfDoubles(double val, int x, std::vector<double> &vector);
	double getFromVectorOfDoubles(int x, std::vector<double> &vector);

	bool setInVectorOfInts(int val, int x, std::vector<int> &vector);
	double getFromVectorOfInts(int x, std::vector<int> &vector);

	Matrix<double> cd, cf, cm;
	std::vector<double> ud, uf, um, sd, sf, sm, ss, ps;
	std::vector<int> minxd, maxxd, minxf, maxxf, minxm, maxxm;
};