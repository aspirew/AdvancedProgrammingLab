#include "pch.h"
#include "mscnProblem.cpp"
//#include <vld.h>

double * solution(int size) {
	double * res = new double[size];

	srand(time(0));
	for (int i = 0; i < size; i++) {
		res[i] = rand() % 100;
	}

	return res;
}

void createAndSaveProblem() {
	MscnProblem problem = MscnProblem();

	double * sol = solution(problem.getValidSize());

	std::cout << problem.getQuality(sol, problem.getValidSize()) << std::endl;
	std::cout << problem.constraintsSatisfied(sol, problem.getValidSize()) << std::endl;

	std::cout << problem;

	problem.saveData(PROBLEM_FILE_NAME);
	problem.saveSolution(sol, SOLUTION_FILE_NAME);

	delete sol;
}

void createAndSaveProblemRandom() {
	MscnProblem problem = MscnProblem();

	problem.setRandomElementsCount(3);
	problem.setRandomValues(20);

	double * sol = solution(problem.getValidSize());

	std::cout << problem.getQuality(sol, problem.getValidSize()) << std::endl;
	std::cout << problem.constraintsSatisfied(sol, problem.getValidSize()) << std::endl;

	std::cout << problem;

	problem.saveData(PROBLEM_FILE_NAME);
	problem.saveSolution(sol, SOLUTION_FILE_NAME);

	delete sol;
}

void readProblemFromTxt(std::string problemFileName) {
	MscnProblem problem = MscnProblem(problemFileName);
	std::cout << problem << std::endl;
}

void checkResizing() {

	MscnProblem problem = MscnProblem();
	std::cout << problem << std::endl;

	problem.setRandomElementsCount(4);

	std::cout << problem << std::endl;

}

int main(){
	//createAndSaveProblemRandom();
	//readProblemFromTxt(PROBLEM_FILE_NAME);
}
