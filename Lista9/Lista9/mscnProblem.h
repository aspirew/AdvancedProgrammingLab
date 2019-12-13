#pragma once
#include <vector>

struct solution {
	Matrix<double> xd, xf, xm;
};

class MscnProblem {
public:

	bool setD(int val);
	bool setF(int val);
	bool setM(int val);
	bool setS(int val);

	bool setInCd(double val, int x, int y);
	bool setInCf(double val, int x, int y);
	bool setInCm(double val, int x, int y);

	bool setInUd(double val, int x);
	bool setInUf(double val, int x);
	bool setInUm(double val, int x);
	bool setInSd(double val, int x);
	bool setInSf(double val, int x);
	bool setInSm(double val, int x);
	bool setInSs(double val, int x);
	bool setInPs(double val, int x);

	double getQuality(double *solution);
	double constraintsSatisfied(double *solution);


private:

	int D, F, M, S;

	bool resizeMatrixesOfD();
	bool resizeMatrixesOfF();
	bool resizeMatrixesOfM();
	bool resizeMatrixesOfS();

	Matrix<double> df, cf, cm;
	std::vector<double> ud, uf, um, sd, sf, sm, ss, ps;
	std::vector<int> minxd, maxxd, minxf, maxxf, minxm, maxxm;
};