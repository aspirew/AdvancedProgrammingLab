#include "pch.h"
#include <iostream>
#include "mscnProblem.cpp"

int main(){

	MscnProblem problem = MscnProblem();
	MscnProblem problem2 = MscnProblem();

	problem.setInSd(6, 1);

	problem.setCountOfD(1);

	problem.setCountOfF(2);

	problem.setCountOfM(3);
	
	problem.setCountOfS(4);

	problem.setInCf(6, 0, 0);
	problem.setInCf(8, 0, 2);
	problem.setInSd(6, 1);

	double * sol = new double[20]{ 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };

	std::cout << problem.getQuality(sol, 20) << std::endl;
	std::cout << problem.constraintsSatisfied(sol, 20) << std::endl;

	std::cout << problem;

	problem.saveData("Input.txt");
	problem.saveSolution(sol, "Input2.txt");

	delete sol;

}
