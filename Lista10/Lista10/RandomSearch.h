#pragma once
#include "mscnProblem.h"
#include "Random.h"

class RandomSearch {
public:
	RandomSearch() { }
	RandomSearch(MscnProblem *problem) { setProblem(problem); }
	~RandomSearch() { delete problem; }
	void setProblem(MscnProblem *problem) { this->problem = problem; }
	MscnSolution findBestSolution(int instanceSeed) { //TODO: move to cpp

		int bestQuality = INT_MIN;
		int solSize = problem->getValidSize();
		MscnSolution sol;
		MscnSolution bestSol;

		if(instanceSeed != 0)
			if (!problem->setRandomClassSeed(instanceSeed)) return bestSol;

		for (int i = 0; i < 100000; i++) {

			sol = problem->generateRandomSolution();

			int currentQuality = problem->getQuality(sol.toDouble(), solSize);

			if (problem->getSolutionErrorState() == SOLUTION_VALID && problem->constraintsSatisfied(sol.toDouble(), solSize)) {
				if (currentQuality > bestQuality) {
					bestSol = sol;
					bestQuality = currentQuality;
				}
			}
		}

		return bestSol;

	}

private:
	MscnProblem * problem;

};