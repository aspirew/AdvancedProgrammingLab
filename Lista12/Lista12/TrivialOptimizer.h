#pragma once
#include "Optimizer.h"

class TrivialOptimizer : Optimizer {
	TrivialOptimizer(int n) {
		this->n = n;
	}
	virtual double getBestScore();
	virtual double * solveProblem(Problem * problem);

private:

	int n;

};