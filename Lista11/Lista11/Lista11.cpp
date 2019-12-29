#include "pch.h"
#include <iostream>
#include "mscnProblem.cpp"
#include "Random.h"
#include "RandomSearch.cpp"
#include "DiffEvol.h"
#include "DiffIndividual.h"
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

	double * sol = solution(problem.getValidSize());

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

	double * sol = problem.generateRandomSolution().toDouble();

	std::cout << "Quality: " << problem.getQuality(sol, problem.getValidSize()) << std::endl;
	std::cout << "Constraints: " << problem.constraintsSatisfied(sol, problem.getValidSize()) << std::endl;

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

	std::cout << "QUALITY: " << problem.getQuality(solDbl, problem.getValidSize());

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

	RandomSearch randSearch = RandomSearch(problem);
	std::cout << *(problem) << std::endl;
	MscnSolution sol = randSearch.findBestSolution(0, exTime);
	double * parsedSol = sol.toDouble();
	std::cout << problem->getSolution(parsedSol) << std::endl;
	std::cout << problem->getQuality(parsedSol, problem->getValidSize());

	delete parsedSol;

}

void diffEvolTest() {
  MscnProblem * problem = new MscnProblem();

  problem->setRandomElementsCount(2);
  problem->generateInstance(0);
  problem->setRandomMinMaxValues(20);

  RandomSearch randSearch = RandomSearch(problem);
  DiffEvol evol = DiffEvol(problem);

  std::cout << *(problem) << std::endl;

  MscnSolution sol = randSearch.findBestSolution(0, 1);
  double * parsedSol = sol.toDouble();
  std::cout << "RANDSEARCH: " << problem->getQuality(parsedSol, problem->getValidSize()) << std::endl;
  delete parsedSol;

  std::cout << "DIFFEVOL: " << evol.getBestFound().getFitness();

}

int main() {
	//createAndSaveProblem();
	//createAndSaveProblemRandom();
	//readProblemFromTxt(PROBLEM_FILE_NAME);
	//checkResize();
	//randomSearchTest(1);
  diffEvolTest();
	//Random rnd = Random(time(NULL));

	//std::cout << rnd.generateDouble(-10, 5) << std::endl;
	//std::cout << rnd.generateInt(-10, 5) << std::endl;
}
