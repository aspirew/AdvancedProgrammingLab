#include "pch.h"
#include <iostream>
#include "mscnProblem.cpp"
#include <sstream>

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

	problem.setRandomElementsCount(2);
	problem.setRandomValues(20);

	double * sol = solution(problem.getValidSize());

	std::cout << problem.getQuality(sol, problem.getValidSize()) << std::endl;
	std::cout << problem.constraintsSatisfied(sol, problem.getValidSize()) << std::endl;

	std::cout << problem;

	problem.saveData("Input.txt");
	problem.saveSolution(sol, "Input2.txt");

	delete sol;
}

void readProblemFromTxt(std::string fileName) {
	MscnProblem problem = MscnProblem(fileName);
	std::cout << problem.getSolutionFromTxt("Input2.txt");
}

int main(){
	readProblemFromTxt("Input.txt");
}
