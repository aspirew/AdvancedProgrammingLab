#pragma once
#include "Optimizer.h"

class EasyAlg : public Optimizer {

public:

	EasyAlg(int n) {
		this->n = n;
	}
	double getBestScore() {
		return 0;
	}

	double * solveProblem(Problem * problem) {
		int size = problem->getSize();
		double * sol = new double[size];
			for (int i = 0; i < size; i++) {
				sol[i] = i % n;
			}
		return sol;
	}

private:

	int n;

};