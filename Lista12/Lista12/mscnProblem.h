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

	bool setInCd(T val, int y, int x);
	bool setInCf(T val, int y, int x);
	bool setInCm(T val, int y, int x);

	T getFromCd(int y, int x);
	T getFromCf(int y, int x);
	T getFromCm(int y, int x);

	bool setInUd(T val, int x);
	bool setInUf(T val, int x);
	bool setInUm(T val, int x);
	bool setInSd(T val, int x);
	bool setInSf(T val, int x);
	bool setInSm(T val, int x);
	bool setInSs(T val, int x);
	bool setInPs(T val, int x);

	T getFromUd(int x);
	T getFromUf(int x);
	T getFromUm(int x);
	T getFromSd(int x);
	T getFromSf(int x);
	T getFromSm(int x);
	T getFromSs(int x);
	T getFromPs(int x);
	
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


	friend std::ostream& operator<<(std::ostream &os, MscnProblem<T> &p) {

		os << "D " << p.d << "\n" << "F " << p.f << "\n";
		os << "M " << p.m << "\n" << "S " << p.s << "\n";
		os << "sd \n" << p.sd << "\n";
		os << "sf \n" << p.sf << "\n";
		os << "sm \n" << p.sm << "\n";
		os << "ss \n" << p.ss << "\n";

		os << "cd \n";
		for (int i = 0; i < p.cd->getHeigth(); i++) {
			for (int j = 0; j < p.cd->getWidth(); j++) {
				os << p.cd->getElem(i, j) << " ";
			}
			os << "\n";
		}

		os << "cf \n";
		for (int i = 0; i < p.cf->getHeigth(); i++) {
			for (int j = 0; j < p.cf->getWidth(); j++) {
				os << p.cf->getElem(i, j) << " ";
			}
			os << "\n";
		}

		os << "cm \n";
		for (int i = 0; i < p.cm->getHeigth(); i++) {
			for (int j = 0; j < p.cm->getWidth(); j++) {
				os << p.cm->getElem(i, j) << " ";
			}
			os << "\n";
		}

		os << "ud \n" << p.ud << "\n";
		os << "uf \n" << p.uf << "\n";
		os << "um \n" << p.um << "\n";

		os << "p \n" << p.ps << "\n";

		os << "minmaxxd \n";
		for (int i = 0; i < p.minmaxxd->getHeigth(); i++) {
			for (int j = 0; j < p.minmaxxd->getWidth(); j++) {
				os << p.minmaxxd->getElem(i, j) << " ";
			}
			os << "\n";
		}

		os << "minmaxxf \n";
		for (int i = 0; i < p.minmaxxf->getHeigth(); i++) {
			for (int j = 0; j < p.minmaxxf->getWidth(); j++) {
				os << p.minmaxxf->getElem(i, j) << " ";
			}
			os << "\n";
		}

		os << "minmaxxm \n";
		for (int i = 0; i < p.minmaxxm->getHeigth(); i++) {
			for (int j = 0; j < p.minmaxxm->getWidth(); j++) {
				os << p.minmaxxm->getElem(i, j) << " ";
			}
			os << "\n";
		}

		return os;
	}


private:

	int d, f, m, s;

	Random rnd = Random();

	bool setInVector(T val, int x, std::vector<T> &vector);
	T getFromVector(int x, std::vector<T> &vector);

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

	void genInstInt();

};
