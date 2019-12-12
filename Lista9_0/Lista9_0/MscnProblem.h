#pragma once
#include <vector>
#include <fstream>
#include "SupplyChainElement.h"
#include "SupplyChainElementsContainer.h"

class MscnProblem {

public:

	MscnProblem(int D, int F, int M, int S);


private:

	SupplyChainElementsContainer chainObjects;

	std::vector<int> allElements;

};