#pragma once
#include "CONST_H.h"
#include "Random.h"

class Problem {
public:
	
	virtual double getQuality(double *solution, int arrSize) = 0;
	virtual bool setRandomClassSeed(int seed) = 0;
	virtual double * generateRandSolution() = 0;
	virtual int getSize() = 0;

};