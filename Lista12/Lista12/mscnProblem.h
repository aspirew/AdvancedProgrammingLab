#pragma once
#include <vector>
#include "Matrix.cpp"
#include "MscnSolution.cpp"
#include "vectorHelper.cpp"
#include "MinMaxValues.h"
#include "Random.h"
#include "Problem.h"

class MscnProblem : public Problem {
public:

	MscnProblem();
	MscnProblem(std::string fileName);
	~MscnProblem();

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
	int constraintsSatisfied(double *solution, int arrSize);

	MscnSolution getSolution(double *solution);
	MscnSolution generateRandomSolution(int seed);
	MscnSolution getSolutionFromTxt(std::string fileName);

	double * generateRandSolution() { return generateRandomSolution(0).toDouble(); }
	int getSize() { return d * f + f * m + m * s; }

	bool saveData(std::string const &path);
	bool saveSolution(double *solution, std::string const &path);

	void setRandomElementsCount(int maxDist);
	void setCorrectRandomMinMaxValues(int maxDist);
	void setRandomMinMaxValues(int maxDist);

	void generateInstance(int instanceSeed);

  std::vector<MinMaxValues> getAllMinMaxValues();
  MinMaxValues getMinMaxValueBy1DimIndex(int index);

	friend std::ostream& operator<<(std::ostream &os, MscnProblem &p);

private:

	int d, f, m, s;

	bool setInVectorOfDoubles(double val, int x, std::vector<double> &vector);
	double getFromVectorOfDoubles(int x, std::vector<double> &vector);

	bool setInVectorOfInts(int val, int x, std::vector<int> &vector);
	double getFromVectorOfInts(int x, std::vector<int> &vector);

	double getKT(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm);
	double getKU(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm);
	double getP(Matrix<double> *xm);

	double getProfit(MscnSolution sol);
	int checkIfSolutionIsValid(double *solution, int arrSize);

	int constraintsCheck(MscnSolution &sol);

	int eps(double x);

	Matrix<double> * cd, * cf, * cm;
	std::vector<double> ud, uf, um, sd, sf, sm, ss, ps;
	Matrix<MinMaxValues> * minmaxxd, * minmaxxf, * minmaxxm;

	void generateMatrix(int width, int heigth, Matrix<MinMaxValues> * minmax, Matrix<double> * x);
	void decrementValuesInX(int size, Matrix<double> * x, std::vector<double> * s, Matrix<MinMaxValues> * minmax);

	void fixSolution(double *solution, int arrSize);
	void fixSolutionForConstraints(MscnSolution * sol, int err);

};