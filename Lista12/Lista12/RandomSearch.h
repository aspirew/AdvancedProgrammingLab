#pragma once
#include "mscnProblem.h"
#include "Optimizer.h"

class RandomSearch : public Optimizer {
public:
	RandomSearch() { }
	RandomSearch(Problem *problem, int time) : Optimizer(problem, time) { }
	~RandomSearch() { }
	double * findBestSolution(int instanceSeed, int time);
	double * findBestSolution(int instanceSeed);
	double * findBestSolution();

	double getBestScore();
	double * solveProblem(Problem * problem) { 
		setProblem(problem);
		return findBestSolution(); 
	};

};
