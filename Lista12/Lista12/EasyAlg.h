#pragma once
#include "Optimizer.h"

template <typename T>
class EasyAlg : public Optimizer<T> {

public:

	EasyAlg(int n) : Optimizer<T>() {
		this->n = n;
	}
	double getBestScore() {
		return 0;
	}

	T * solveProblem(Problem<T> * problem) {
		int size = problem->getSize();
		T * sol = new T[size];
			for (int i = 0; i < size; i++) {
				sol[i] = i % n;
			}
		return sol;
	}

private:

	int n;

};