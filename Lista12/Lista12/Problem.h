#pragma once
#include "CONST_H.h"
#include "Random.h"

class Problem {
public:
	
	virtual double getQuality(double *solution, int arrSize) = 0;
	virtual bool saveData(std::string const &path) = 0;
	virtual bool saveSolution(double *solution, std::string const &path) = 0;
	virtual void generateInstance(int instanceSeed) = 0;
	virtual bool setRandomClassSeed(int seed) { return rnd.setSeed(seed); }
	virtual double * generateRandSolution() = 0;
	virtual int getSize() = 0;
	virtual int getSolutionErrorState() { return solutionErrorState; }
	virtual int constraintsSatisfied(double *solution, int arrSize) = 0;

protected:

	virtual int checkIfSolutionIsValid(double *solution, int arrSize) = 0;
	
	int solutionErrorState = 0;
	Random rnd = Random();



};