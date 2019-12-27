#include "RandomSearch.h"

//double * RandomSearch::findBestSolution() {
//
//	Random rnd;
//
//	int bestQuality = INT_MIN;
//	int solSize = problem->getValidSize();
//
//	double * sol = new double[solSize];
//	double * bestSol;
//
//	for (int i = 0; i < 100; i++) {
//
//		sol = generateSolution(rnd);
//		int currentQuality = problem->getQuality(sol, solSize);
//
//		if (problem->getSolutionErrorState() == SOLUTION_VALID && problem->constraintsSatisfied(sol, solSize)) {
//			if (currentQuality > bestQuality) {
//				bestSol = sol;
//				bestQuality = currentQuality;
//			}
//		}
//
//	}
//
//	return bestSol;
//	
//}

/*double * RandomSearch::generateSolution(Random &rnd) {

	double * sol = new double[problem->getValidSize()];

	for (int i = 0; i < problem->getMinMaxXd()->getHeigth(); i++) {
		for (int j = 0; j < problem->getMinMaxXd()->getWidth(); j++) {
			int index = i * problem->getMinMaxXd()->getWidth() + j;
			sol[index] = rnd.generateDouble(problem->getMinMaxXd()->getElem(i, j).min, problem->getMinMaxXd()->getElem(i, j).max);
		}
	}

	for (int i = 0; i < problem->getMinMaxXf()->getHeigth(); i++) {
		for (int j = 0; j < problem->getMinMaxXf()->getWidth(); j++) {
			int index = problem->getMinMaxXd()->getHeigth() * problem->getMinMaxXd()->getWidth() + i * problem->getMinMaxXf()->getWidth() + j;
			sol[index] = rnd.generateDouble(problem->getMinMaxXf()->getElem(i, j).min, problem->getMinMaxXf()->getElem(i, j).max);
		}
	}

	for (int i = 0; i < problem->getMinMaxXm()->getHeigth(); i++) {
		for (int j = 0; j < problem->getMinMaxXm()->getWidth(); j++) {
			int index = problem->getMinMaxXd()->getHeigth() * problem->getMinMaxXd()->getWidth() + problem->getMinMaxXf()->getHeigth() * problem->getMinMaxXf()->getWidth() + i * problem->getMinMaxXm()->getWidth() + j;
			sol[index] = rnd.generateDouble(problem->getMinMaxXm()->getElem(i, j).min, problem->getMinMaxXm()->getElem(i, j).max);
		}
	}

	return sol;
}*/