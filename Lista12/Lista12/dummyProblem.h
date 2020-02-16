#pragma once
#include "Problem.h"

template <typename T>
class dummyProblem : public Problem<T> {

public:

	dummyProblem() : Problem<T>() {}

	bool saveData(std::string const &path) { return false; }
	bool saveSolution(T *solution, std::string const &path) { return false; }
	double getQuality(T *solution, int arrSize) { return 0; }
	bool setRandomClassSeed(int seed) { return false; }
	T * generateRandSolution() { return NULL; }
	int getSize() { return 10; }
};
