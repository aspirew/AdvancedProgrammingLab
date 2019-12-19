#include "pch.h"
#include <iostream>
#include "mscnProblem.cpp"
//#include "vld.h"

double * solution(int size) {
	double * res = new double[size];

	srand(time(0));
	for (int i = 0; i < size; i++) {
		res[i] = 50;
	}

	return res;
}

void createAndSaveProblem() {
	MscnProblem problem = MscnProblem();
	problem.setRandomElementsCount(2);

	double * sol = solution(problem.getValidSize());

	std::cout << problem;

	std::cout << "Quality: " << problem.getQuality(sol, problem.getValidSize());

	problem.saveData(PROBLEM_FILE_NAME);
	problem.saveSolution(sol, SOLUTION_FILE_NAME);

	delete sol;

}

void createAndSaveProblemRandom() {
	MscnProblem problem = MscnProblem();

	problem.setRandomElementsCount(2);
	problem.setRandomValues(20);
	problem.setRandomMinMaxValues(50);

	double * sol = solution(problem.getValidSize());

	std::cout << "Quality: " << problem.getQuality(sol, problem.getValidSize()) << std::endl;
	std::cout << "Constraints: " << problem.constraintsSatisfied(sol, problem.getValidSize()) << std::endl;

	//std::cout << problem;

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
}

void checkResize() {
	MscnProblem problem = MscnProblem();

	problem.setRandomElementsCount(6);
	problem.setRandomValues(100);
	problem.setRandomMinMaxValues(50);

	std::cout << problem << std::endl;

	problem.setRandomElementsCount(2);

	std::cout << problem;

}

int main(){
	//createAndSaveProblem();
	createAndSaveProblemRandom();
	readProblemFromTxt(PROBLEM_FILE_NAME);
	//checkResize();
}
