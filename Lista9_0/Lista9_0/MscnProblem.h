#pragma once
#include <vector>
#include <fstream>
#include "CONST_H.h"
#include "SupplyChainElement.h"
#include "SupplyChainElementsContainer.h"


class MscnProblem {

public:

	MscnProblem();
	MscnProblem(int D, int F, int M, int S);

	void setValues();

	void setValuesToCDArray();
	void setValuesToCFArray();
	void setValuesToCMArray();

	void createCDArray();
	void createCFArray();
	void createCMArray();

	void packToVector();

	void printAll();


private:

	SupplyChainElementsContainer chainObjects;

	//setValues

	std::vector<double **> allElements; //TODO: destruktor

	double * cd;
	double * cf;
	double * cm;
	//TODO: destruktory
};