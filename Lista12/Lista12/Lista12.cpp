#include "pch.h"
#include <iostream>
#include "mscnProblem.cpp"
#include "Random.h"
#include "RandomSearch.cpp"
#include "DiffEvolution.cpp"
//#include "vld.h"

double * solution(int size) {
	double * res = new double[size];

	for (int i = 0; i < size; i++) {
		res[i] = 50.0;
	}

	return res;
}

void createAndSaveProblem() {
	MscnProblem problem = MscnProblem();

	problem.setRandomMinMaxValues(50);

	double * sol = solution(problem.getSize());

	std::cout << problem;

	problem.saveData(PROBLEM_FILE_NAME);
	problem.saveSolution(sol, SOLUTION_FILE_NAME);

	delete sol;

}

int seedFromTxt(std::string fileName) {
	FILE * pFile;
	pFile = fopen(fileName.c_str(), "r+");

	if (!pFile) return 0;

	std::ifstream is(pFile);

	int res = 0;
	is >> res;

	is.close();
	fclose(pFile);

	return res;
}

void createAndSaveProblemRandom() {
	MscnProblem problem = MscnProblem();

	problem.setRandomElementsCount(2);
	problem.generateInstance(time(NULL));
	problem.setRandomMinMaxValues(20);

	double * sol = problem.generateRandomSolution(0).toDouble();

	std::cout << "Quality: " << problem.getQuality(sol, problem.getSize()) << std::endl;
	std::cout << "Constraints: " << problem.constraintsSatisfied(sol, problem.getSize()) << std::endl;

	std::cout << problem;

	problem.saveData(PROBLEM_FILE_NAME);
	problem.saveSolution(sol, SOLUTION_FILE_NAME);

	delete sol;
}

void readProblemFromTxt(std::string fileName) {
	MscnProblem problem = MscnProblem(fileName);
	MscnSolution solution = problem.getSolutionFromTxt(SOLUTION_FILE_NAME);

	std::cout << "PROBLEM: ";

	std::cout << problem;

	std::cout << "SOLUTION: " << std::endl;

	std::cout << solution;

	double * solDbl = solution.toDouble();

	std::cout << "QUALITY: " << problem.getQuality(solDbl, problem.getSize());

	delete solDbl;
}

void checkResize() {
	MscnProblem problem = MscnProblem();

	problem.setRandomElementsCount(6);
	problem.generateInstance(time(NULL));
	problem.setRandomMinMaxValues(50);

	std::cout << problem << std::endl;

	problem.setRandomElementsCount(2);

	std::cout << problem;

}

void randomSearchTest(int exTime) {

	MscnProblem * problem = new MscnProblem();

	problem->setRandomElementsCount(2);
	problem->generateInstance(0);
	problem->setRandomMinMaxValues(20);

	RandomSearch randSearch = RandomSearch(problem, exTime);
	//std::cout << *(problem) << std::endl;
	double * sol = randSearch.findBestSolution(0);
	//std::cout << problem->getSolution(parsedSol) << std::endl;
	std::cout << "Quality of randomSearch: " << problem->getQuality(sol, problem->getSize()) << std::endl;

	delete problem;
	delete sol;

}

void diffEvolTest(int iterations, int populationNumber) {

	MscnProblem * problem = new MscnProblem();

	problem->setRandomElementsCount(2);
	problem->generateInstance(0);
	problem->setRandomMinMaxValues(20);

	std::cout << *(problem);

	DiffEvolution evol = DiffEvolution(problem, 0.5, 0.1, problem->getAllMinMaxValues(), 10);
	DiffInd * ind = evol.getBestFound(iterations, populationNumber);

	std::cout << "Quality of DiffEvol: " << ind->getFitness() << std::endl;

	delete problem;

}

double optimizerTest(Optimizer * optimizer) {
	return optimizer->getBestScore();
}

double * solveProblem(Optimizer * optimizer, Problem * problem) {
	return optimizer->solveProblem(problem);
}

void problemsTest() {

	Problem * problem = new MscnProblem();

	((MscnProblem*)problem)->setRandomElementsCount(2);
	((MscnProblem*)problem)->generateInstance(0);
	((MscnProblem*)problem)->setRandomMinMaxValues(20);

	//std::cout << *((MscnProblem*)problem);

	DiffEvolution * evol = new DiffEvolution(((MscnProblem*)problem), 0.5, 0.1, ((MscnProblem*)problem)->getAllMinMaxValues(), 1);
	RandomSearch * randSearch = new RandomSearch(((MscnProblem*)problem), 1);

	//std::cout << "DiffEvol: " << optimizerTest(evol) << std::endl;
	//std::cout << "RandSearch: " << optimizerTest(randSearch);

	std::cout << "DiffEvol: " << std::endl;
	double * solvedProblem = solveProblem(evol, problem);
	for (int i = 0; i < problem->getSize(); i++) {
		std::cout << solvedProblem[i] << " ; ";
	}
	delete solvedProblem;
	std::cout << std::endl;
	std::cout << "RandSearch: " << std::endl;
	solvedProblem = solveProblem(randSearch, problem);
	for (int i = 0; i < problem->getSize(); i++) {
		std::cout << solvedProblem[i] << " ; ";
	}

	delete solvedProblem;
	delete evol;
	delete randSearch;
	delete problem;

}

int main() {
	//createAndSaveProblem();
	//createAndSaveProblemRandom();
	//readProblemFromTxt(PROBLEM_FILE_NAME);
	//checkResize();
	//diffEvolTest(10000, 1);
	//randomSearchTest(1);

	problemsTest();

}
