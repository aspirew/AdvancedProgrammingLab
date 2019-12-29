#include "RandomSearch.h"
#include "Random.h"
#include <chrono>

MscnSolution RandomSearch::findBestSolution(int instanceSeed, int time) {

	int bestQuality = INT_MIN;
	int solSize = problem->getValidSize();
	MscnSolution sol;
	MscnSolution bestSol;

	if (instanceSeed != 0)
		if (!problem->setRandomClassSeed(instanceSeed)) return bestSol;

	auto t1 = std::chrono::high_resolution_clock::now();
	auto t2 = std::chrono::high_resolution_clock::now();

	do {
		sol = problem->generateRandomSolution();

		double * solParsed = sol.toDouble();
		int currentQuality = problem->getQuality(solParsed, solSize);

		if (problem->getSolutionErrorState() == SOLUTION_VALID && problem->constraintsSatisfied(solParsed, solSize)) {
			if (currentQuality > bestQuality) {
				bestSol = sol;
				bestQuality = currentQuality;
			}
		}
		delete solParsed;
		t2 = std::chrono::high_resolution_clock::now();
	} while (std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() < time);

	

	return bestSol;

}
