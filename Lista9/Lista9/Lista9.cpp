#include "pch.h"
#include <iostream>
#include "mscnProblem.cpp"

int main(){

	MscnProblem problem = MscnProblem();
	std::cout << "initialized" << std::endl;

	problem.setInSd(6, 1);

	problem.setCountOfD(1);

	std::cout << "changed d" << std::endl;

	problem.setCountOfF(2);

	std::cout << "changed f" << std::endl;

	problem.setCountOfM(3);
	
	std::cout << "changed m" << std::endl;
	
	problem.setCountOfS(4);

	problem.setInCf(6, 0, 0);
	problem.setInCf(8, 0, 2);
	problem.setInSd(6, 1);

	problem.printAll();

	double * sol = new double[20]{ 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };

	std::cout << problem.getQuality(sol, 20);


}
