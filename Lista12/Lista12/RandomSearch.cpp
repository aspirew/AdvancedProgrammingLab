#include "RandomSearch.h"
#include "Random.h"
#include <chrono>

double * RandomSearch::findBestSolution(int instanceSeed, int time) {

	timer.setTime(time);
	return findBestSolution(0);

}

double * RandomSearch::findBestSolution()
{
	return findBestSolution(0, DEFAULT_TIME);
}

double * RandomSearch::findBestSolution(int instanceSeed)
{
	int bestQuality = INT_MIN;
	int solSize = problem->getSize();
	double * sol;
	double * bestSol = new double[0]();

	if (instanceSeed != 0)
		if (!problem->setRandomClassSeed(instanceSeed)) return bestSol;

	timer.startTimer();

	do {

		bool bestChange = false;
		sol = problem->generateRandSolution();
		int currentQuality = problem->getQuality(sol, solSize);

		if (problem->getSolutionErrorState() == SOLUTION_VALID) {
			if (currentQuality > bestQuality) {
				delete bestSol;
				bestSol = sol;
				bestQuality = currentQuality;
				bestChange = true;
			}
		}
		if (!bestChange) delete sol;
	} while (!timer.hasTimePassed());

	return bestSol;
}

double RandomSearch::getBestScore()
{
	return problem->getQuality(findBestSolution(0, DEFAULT_TIME), problem->getSize());
}
