#pragma once
#include "mscnProblem.h"
#include "Optimizer.h"

template <typename T>
class RandomSearch : public Optimizer<T> {
public:
	RandomSearch() : Optimizer<T>() { }
	RandomSearch(Problem<T> *problem, int time) : Optimizer<T>(problem, time) { }
	~RandomSearch() { }
	T * findBestSolution(int instanceSeed, int time);
	T * findBestSolution(int instanceSeed);
	T * findBestSolution();

	double getBestScore();
	T * solveProblem(Problem<T> * problem) { 
		this->setProblem(problem);
		return findBestSolution(); 
	};

private:

	//void setSeed(int seed);

};
