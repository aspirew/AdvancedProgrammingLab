#include "pch.h"
#include <iostream>
#include "mscnProblem.cpp"
#include "Random.h"
#include "RandomSearch.cpp"
#include "DiffEvolution.cpp"
#include "EasyAlg.h"
#include "dummyProblem.h"
//#include "vld.h"

double * solution(int size) {
	double * res = new double[size];

	for (int i = 0; i < size; i++) {
		res[i] = 50.0;
	}

	return res;
}

void createAndSaveProblem() {
	MscnProblem<double> problem = MscnProblem<double>();

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
	MscnProblem<double> problem = MscnProblem<double>();

	problem.setRandomElementsCount(2);
	problem.generateInstance(time(NULL));
	problem.setRandomMinMaxValues(20);

	double * sol = problem.generateRandomSolution(0).toTypeTable();

	std::cout << "Quality: " << problem.getQuality(sol, problem.getSize()) << std::endl;
	std::cout << "Constraints: " << problem.constraintsSatisfied(sol, problem.getSize()) << std::endl;

	std::cout << problem;

	problem.saveData(PROBLEM_FILE_NAME);
	problem.saveSolution(sol, SOLUTION_FILE_NAME);

	delete sol;
}

void readProblemFromTxt(std::string fileName) {
	MscnProblem<double> problem = MscnProblem<double>(fileName);
	MscnSolution<double> solution = problem.getSolutionFromTxt(SOLUTION_FILE_NAME);

	std::cout << "PROBLEM: ";

	std::cout << problem;

	std::cout << "SOLUTION: " << std::endl;

	std::cout << solution;

	double * solDbl = solution.toTypeTable();

	std::cout << "QUALITY: " << problem.getQuality(solDbl, problem.getSize());

	delete solDbl;
}

void checkResize() {
	MscnProblem<double> problem = MscnProblem<double>();

	problem.setRandomElementsCount(6);
	problem.generateInstance(time(NULL));
	problem.setRandomMinMaxValues(50);

	std::cout << problem << std::endl;

	problem.setRandomElementsCount(2);

	std::cout << problem;

}

void randomSearchTest(int exTime) {

	MscnProblem<double> * problem = new MscnProblem<double>();

	problem->setRandomElementsCount(2);
	problem->generateInstance(0);
	problem->setRandomMinMaxValues(20);

	RandomSearch<double> randSearch = RandomSearch<double>(problem, exTime);
	//std::cout << *(problem) << std::endl;
	double * sol = randSearch.findBestSolution(0);
	//std::cout << problem->getSolution(parsedSol) << std::endl;
	std::cout << "Quality of randomSearch: " << problem->getQuality(sol, problem->getSize()) << std::endl;

	delete problem;
	delete sol;

}

template <typename T>
void diffEvolTest(int iterations, int populationNumber) {

	MscnProblem * problem = new MscnProblem();

	problem->setRandomElementsCount(2);
	problem->generateInstance(0);
	problem->setRandomMinMaxValues(20);

	std::cout << *(problem);

	DiffEvolution<double> evol = DiffEvolution<double>(problem, 0.5, 0.1, problem->getAllMinMaxValues(), 10);
	DiffInd<T> * ind = evol.getBestFound(iterations, populationNumber);

	std::cout << "Quality of DiffEvol: " << ind->getFitness() << std::endl;

	delete problem;

}


template <typename T>
double optimizerTest(Optimizer<T> * optimizer) {
	return optimizer->getBestScore();
}

template <typename T>
T * solveProblem(Optimizer<T> * optimizer, Problem<T> * problem) {
	return optimizer->solveProblem(problem);
}

void problemsTest() {

	Problem<double> * problem = new MscnProblem<double>();

	((MscnProblem<double>*)problem)->setRandomElementsCount(2);
	((MscnProblem<double>*)problem)->generateInstance(0);
	((MscnProblem<double>*)problem)->setRandomMinMaxValues(20);

	std::cout << *((MscnProblem<double>*)problem);

	DiffEvolution<double> * evol = new DiffEvolution<double>(((MscnProblem<double>*)problem), 0.5, 0.1, ((MscnProblem<double>*)problem)->getAllMinMaxValues(), 1);
	RandomSearch<double> * randSearch = new RandomSearch<double>(((MscnProblem<double>*)problem), 1);

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

void easyProblem() {

	Problem<double> * problem = new MscnProblem<double>();

	((MscnProblem<double>*)problem)->setRandomElementsCount(2);
	((MscnProblem<double>*)problem)->generateInstance(0);
	((MscnProblem<double>*)problem)->setRandomMinMaxValues(20);

	EasyAlg<double> * easy = new EasyAlg<double>(5);

	std::cout << "EasyAlg: " << std::endl;
	double * solvedProblem = solveProblem<double>(easy, problem);
	for (int i = 0; i < problem->getSize(); i++) {
		std::cout << solvedProblem[i] << " ; ";
	}

}

void wrongProblemsTest() {

	Problem<float> * problem = new dummyProblem<float>;
	EasyAlg<std::string> * easy = new EasyAlg<std::string>(5);

}

void problemsTestForInt() {
	Problem<int> * problem = new MscnProblem<int>();

	((MscnProblem<int>*)problem)->setRandomElementsCount(2);
	((MscnProblem<int>*)problem)->generateInstance(0);
	((MscnProblem<int>*)problem)->setRandomMinMaxValues(20);

	std::cout << *((MscnProblem<double>*)problem);

	DiffEvolution<int> * evol = new DiffEvolution<int>(((MscnProblem<int>*)problem), 0.5, 0.1, ((MscnProblem<int>*)problem)->getAllMinMaxValues(), 1);
	RandomSearch<int> * randSearch = new RandomSearch<int>(((MscnProblem<int>*)problem), 1);

	//std::cout << "DiffEvol: " << optimizerTest(evol) << std::endl;
	//std::cout << "RandSearch: " << optimizerTest(randSearch);

	std::cout << "DiffEvol: " << std::endl;
	int * solvedProblem = solveProblem(evol, problem);
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

	//problemsTest();
	//easyProblem();

	problemsTestForInt();
	//wrongProblemsTest();

}
