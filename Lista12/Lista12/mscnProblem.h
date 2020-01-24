#pragma once
#include <vector>
#include "Matrix.cpp"
#include "MscnSolution.cpp"
#include "vectorHelper.cpp"
#include "MinMaxValues.h"
#include "Random.h"
#include "Problem.h"

template <typename T>
class MscnProblem : public Problem<T> {
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
	
	double getQuality(T *solution, int arrSize);
	int constraintsSatisfied(T *solution, int arrSize);

	MscnSolution<T> getSolution(T *solution);
	MscnSolution<T> generateRandomSolution(int seed);
	MscnSolution<T> getSolutionFromTxt(std::string fileName);

	T * generateRandSolution() { return generateRandomSolution(0).toTypeTable(); }
	int getSize() { return d * f + f * m + m * s; }

	bool saveData(std::string const &path);
	bool saveSolution(T *solution, std::string const &path);

	void setRandomElementsCount(int maxDist);
	void setCorrectRandomMinMaxValues(int maxDist);
	void setRandomMinMaxValues(int maxDist);

	void generateInstance(int instanceSeed);

	bool setRandomClassSeed(int seed) { return rnd.setSeed(seed); }

  std::vector<MinMaxValues<T>> getAllMinMaxValues();
  MinMaxValues<T> getMinMaxValueBy1DimIndex(int index);

	friend std::ostream& operator<<(std::ostream &os, MscnProblem<T> &p);

private:

	int d, f, m, s;

	Random rnd = Random();

	bool setInVectorOfDoubles(double val, int x, std::vector<double> &vector);
	double getFromVectorOfDoubles(int x, std::vector<double> &vector);

	bool setInVectorOfInts(int val, int x, std::vector<int> &vector);
	int getFromVectorOfInts(int x, std::vector<int> &vector);

	T getKT(Matrix<T> *xd, Matrix<T> *xf, Matrix<T> *xm);
	T getKU(Matrix<T> *xd, Matrix<T> *xf, Matrix<T> *xm);
	T getP(Matrix<T> *xm);

	double getProfit(MscnSolution<T> sol);
	int checkIfSolutionIsValid(T *solution, int arrSize);

	int constraintsCheck(MscnSolution<T> &sol);

	int eps(T x);

	int solutionErrorState = 0;

	Matrix<T> * cd, * cf, * cm;
	std::vector<T> ud, uf, um, sd, sf, sm, ss, ps;
	Matrix<MinMaxValues<T>> * minmaxxd, * minmaxxf, * minmaxxm;

	void generateMatrix(int width, int heigth, Matrix<MinMaxValues<T>> * minmax, Matrix<T> * x);
	void decrementValuesInX(int size, Matrix<T> * x, std::vector<T> * s, Matrix<MinMaxValues<T>> * minmax);
	void fixColumnsAndRowsSumIssue(int sizeOfChild, int sizeOfGrandChild, Matrix<T> * parentX, Matrix<T> * childX, Matrix<MinMaxValues<T>> * parentMinMax, Matrix<MinMaxValues<T>> * childMinMax);

	void fixSolution(T *solution, int arrSize);
	void fixSolutionForConstraints(MscnSolution<T> * sol, int err);

};
