#pragma once
#include "mscnProblem.h"

class RandomSearch {
public:
	RandomSearch() { }
	RandomSearch(MscnProblem *problem) { setProblem(problem); }
	~RandomSearch() { }
	void setProblem(MscnProblem *problem) { this->problem = problem; }
	MscnSolution findBestSolution(int instanceSeed, int time);

private:
	MscnProblem * problem;

};
