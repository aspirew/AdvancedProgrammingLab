#include "pch.h"
#include <iostream>
#include "mscnProblem.cpp"

int main(){
    
	MscnProblem problem = MscnProblem();
	std::cout << "initialized" << std::endl;

	problem.setInCd(3, 1, 0);
	problem.setInCd(8, 0, 2);
	problem.setInSd(6, 1);

	problem.setCountOfD(3);

	std::cout << "changed d" << std::endl;

	//problem.setCountOfF(4);

	std::cout << "changed f" << std::endl;

	problem.setCountOfM(5);
	
	std::cout << "changed m" << std::endl;
	
	problem.setCountOfS(3);

	problem.setInCf(6, 0, 0);
	problem.setInCf(8, 0, 2);
	problem.setInSd(6, 1);

	problem.printAll();
}
