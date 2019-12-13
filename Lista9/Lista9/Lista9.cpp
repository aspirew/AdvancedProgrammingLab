#include "pch.h"
#include <iostream>
#include "mscnProblem.cpp"

int main(){
    
	MscnProblem problem = MscnProblem();
	std::cout << "initialized" << std::endl;

	for (int i = 0; i < problem.d; i++) {
		for (int j = 0; j < problem.f; j++) {
			problem.setInCd(i+j, i, j);
		}
	}

	problem.setInSd(6, 1);

	problem.setCountOfD(3);

	std::cout << "changed d" << std::endl;

	problem.setCountOfF(2);

	std::cout << "changed f" << std::endl;

	problem.setCountOfM(5);
	
	std::cout << "changed m" << std::endl;
	
	problem.setCountOfS(3);

	problem.setInCf(6, 0, 0);
	problem.setInCf(8, 0, 2);
	problem.setInSd(6, 1);

	problem.printAll();
}
