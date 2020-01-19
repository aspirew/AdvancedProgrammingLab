#pragma once
#include "Problem.h"
#include "Timer.h"
class Optimizer {
public:

	Optimizer() { }
	Optimizer(Problem *problem, int time) { 
		setProblem(problem);
		timer = Timer(time);
	}

	void setProblem(Problem *problem) {
		this->problem = problem;
	}

	virtual double getBestScore() = 0;
	virtual double * solveProblem(Problem * problem) = 0;

protected:

	Problem * problem;
	Timer timer;

};